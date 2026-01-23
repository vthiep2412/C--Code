#include <wx/wx.h>
#include <wx/combobox.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/string.h>
#include <wx/event.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/app.h>
#include <wx/icon.h>
#include <wx/log.h> // For logging errors

#include <thread>
#include <chrono>
#include <string>
#include <vector>
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <cmath> // For std::abs

// Windows specific headers for low-level input and window management
#ifdef _WIN32
#include <windows.h>
#include <winuser.h>
#endif

// --- Forward Declarations ---
class HypcroFrame;

// --- Global State Variables (Accessed by hook and GUI threads) ---
// Using atomic for simple flags accessed by multiple threads
std::atomic<bool> g_toggle(false);
std::atomic<bool> g_hold_mode(false);
std::atomic<bool> g_app_enabled(false);
std::atomic<bool> g_is_binding(false);
std::atomic<bool> g_x_is_held(false); // Tracks if the hotkey is currently physically held down

// Using mutex for variables that require more complex synchronization
std::mutex g_state_mutex;
std::string g_selected_type = "Diagonal";
std::string g_selected_side = "Right";
std::string g_toggle_mode = "Smart Mode";
std::string g_current_hotkey = "X"; // Default hotkey
std::chrono::high_resolution_clock::time_point g_last_toggle_time = std::chrono::high_resolution_clock::now();

// Smart Mode specific state
std::mutex g_smart_mode_mutex;
std::chrono::high_resolution_clock::time_point g_smart_press_time;
std::atomic<bool> g_smart_held(false);
std::atomic<bool> g_smart_check_running(false); // Flag to prevent multiple check_hold threads

// --- Windows Hook Variables ---
#ifdef _WIN32
HHOOK g_keyboard_hook = NULL;
HHOOK g_bind_hook = NULL; // Separate hook for binding
std::thread g_hook_thread;
std::thread g_bind_hook_thread;
DWORD g_hook_thread_id = 0;
DWORD g_bind_hook_thread_id = 0;

// Custom Windows message for hook events
#define WM_HOOK_EVENT (WM_USER + 1)

// Structure to pass data from hook to GUI thread
struct HookEventData {
    DWORD vkCode;
    bool isPress; // true for press, false for release
};
#endif

// --- Input Simulation Functions (Windows specific) ---
#ifdef _WIN32
void SendKeyboardInput(WORD vkCode, bool isPress) {
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = vkCode;
    input.ki.dwFlags = isPress ? 0 : KEYEVENTF_KEYUP;
    SendInput(1, &input, sizeof(INPUT));
}

void SendMouseInput(DWORD flags) {
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = flags;
    SendInput(1, &input, sizeof(INPUT));
}

// Map char to VK code (basic implementation, needs expansion for non-alphanumeric)
WORD CharToVkCode(char c) {
    c = toupper(c);
    if (c >= 'A' && c <= 'Z') return c;
    if (c >= '0' && c <= '9') return c;
    // Add more mappings as needed (e.g., space, enter, etc.)
    // For 'X', it's simply 'X'
    return 0; // Indicate not found
}
#endif

// --- Core Logic Functions ---

// Function to process key press actions (called from GUI thread via message)
void ProcessKeyPress(HypcroFrame* frame) {
    std::lock_guard<std::mutex> lock(g_state_mutex);
    std::string side = g_selected_side;
    std::string type = g_selected_type;

#ifdef _WIN32
    // Simulate keyboard presses
    SendKeyboardInput(CharToVkCode('W'), true);
    if (type == "Diagonal") {
        SendKeyboardInput(CharToVkCode(side == "Right" ? 'D' : 'A'), true);
    } else { // Horizontal Mode
        SendKeyboardInput(CharToVkCode(side == "Right" ? 'D' : 'A'), true);
    }
    // Simulate mouse left click press
    SendMouseInput(MOUSEEVENTF_LEFTDOWN);
#endif
}

// Function to process key release actions (called from GUI thread via message)
void ProcessKeyRelease(HypcroFrame* frame) {
#ifdef _WIN32
    // Simulate keyboard releases
    SendKeyboardInput(CharToVkCode('W'), false);
    SendKeyboardInput(CharToVkCode('D'), false);
    SendKeyboardInput(CharToVkCode('A'), false);
    // Simulate mouse left click release
    SendMouseInput(MOUSEEVENTF_LEFTUP);
#endif
}

// --- GUI Class Definition ---

class HypcroFrame : public wxFrame {
public:
    HypcroFrame(const wxString& title);
    ~HypcroFrame();

private:
    // GUI Controls
    wxComboBox* m_statusDropdown;
    wxComboBox* m_minimizeDropdown;
    wxComboBox* m_toggleModeDropdown;
    wxComboBox* m_typeDropdown;
    wxComboBox* m_directionDropdown;
    wxButton* m_changeBindBtn;
    wxStaticText* m_hotkeyLabel;
    wxStaticText* m_statusWord;
    wxCheckBox* m_alwaysOnTopCheckbox;

    // State Variables (synced with global state)
    wxString m_statusVar;
    wxString m_minimizeVar;
    wxString m_toggleModeVar;
    wxString m_typeVar;
    wxString m_directionVar;
    wxString m_currentHotkeyVar;
    bool m_alwaysOnTopVar = false;

    // Window handle for minimize/restore
#ifdef _WIN32
    HWND m_appWindow = NULL;
#endif

    // Event Handlers
    void OnStatusChange(wxCommandEvent& event);
    void OnMinimizeChange(wxCommandEvent& event);
    void OnAlwaysOnTopToggle(wxCommandEvent& event);
    void OnToggleModeChange(wxCommandEvent& event);
    void OnTypeChange(wxCommandEvent& event);
    void OnDirectionChange(wxCommandEvent& event);
    void OnChangeBindClick(wxCommandEvent& event);
    void OnHookEvent(wxCommandEvent& event); // Custom event handler for hook messages

    // Helper Functions
    void UpdateStatusLabel();
    void UpdateHotkeyLabel();
    void MinimizeIfNeeded(bool state);
    void StartBinding();
#ifdef _WIN32
    void StartKeyListener();
    void StopKeyListener();
    void StartBindListener();
    void StopBindListener();
#endif

    // Smart Mode Helper
    void CheckHold();

    // Event table declaration
    wxDECLARE_EVENT_TABLE();
};

// --- Event Table Implementation ---
wxBEGIN_EVENT_TABLE(HypcroFrame, wxFrame)
    EVT_COMBOBOX(wxID_ANY, HypcroFrame::OnStatusChange) // Need to map specific IDs or use FindWindow
    EVT_COMBOBOX(wxID_ANY, HypcroFrame::OnMinimizeChange)
    EVT_COMBOBOX(wxID_ANY, HypcroFrame::OnToggleModeChange)
    EVT_COMBOBOX(wxID_ANY, HypcroChange)
    EVT_COMBOBOX(wxID_ANY, HypcroFrame::OnDirectionChange)
    EVT_BUTTON(wxID_ANY, HypcroFrame::OnChangeBindClick)
    EVT_CHECKBOX(wxID_ANY, HypcroFrame::OnAlwaysOnTopToggle)
    // Custom event for hook messages
    EVT_COMMAND(wxID_ANY, wxEVT_NULL, HypcroFrame::OnHookEvent) // Using wxEVT_NULL as a placeholder, will define custom event type
wxEND_EVENT_TABLE()

// Define a custom event type for hook messages
wxDEFINE_EVENT(wxEVT_HOOK_EVENT, wxCommandEvent);


// --- GUI Class Implementation ---

HypcroFrame::HypcroFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(400, 250), wxDEFAULT_FRAME_STYLE | wxSTAY_ON_TOP) {
    // Lock window size
    SetMinSize(GetSize());
    SetMaxSize(GetSize());

    // Set window icon (platform dependent)
    // In wxWidgets, you typically add an .ico file to your project resources
    // and load it here. This replaces the Python icon logic.
    wxIcon icon;
    // Assuming 'icon.ico' is available in a standard resource location or path
    if (icon.LoadFile("icon.ico", wxBITMAP_TYPE_ICO)) {
        SetIcon(icon);
    } else {
        wxLogWarning("Could not load icon.ico");
    }

    // Use a sizer for layout
    wxBoxSizer* mainSizer = new wxBoxSizer(wxVERTICAL);
    SetSizer(mainSizer);

    // ON/OFF & Auto Minimize Dropdowns (Side by Side)
    wxBoxSizer* topSizer = new wxBoxSizer(wxHORIZONTAL);

    topSizer->Add(new wxStaticText(this, wxID_ANY, "Able toggle:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT, 5);
    wxArrayString statusChoices;
    statusChoices.Add("ON");
    statusChoices.Add("OFF");
    m_statusDropdown = new wxComboBox(this, wxID_ANY, "OFF", wxDefaultPosition, wxSize(80, -1), statusChoices, wxCB_READONLY);
    m_statusDropdown->Bind(wxEVT_COMBOBOX, &HypcroFrame::OnStatusChange, this); // Bind event handler
    m_statusDropdown->SetValue("OFF"); // Initial value
    m_statusVar = "OFF"; // Sync internal state
    topSizer->Add(m_statusDropdown, 0, wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT, 5);

    topSizer->Add(new wxStaticText(this, wxID_ANY, "Auto Minimize:"), 0, wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT, 5);
    wxArrayString minimizeChoices;
    minimizeChoices.Add("Enabled");
    minimizeChoices.Add("Disabled");
    m_minimizeDropdown = new wxComboBox(this, wxID_ANY, "Disabled", wxDefaultPosition, wxSize(100, -1), minimizeChoices, wxCB_READONLY);
    m_minimizeDropdown->Bind(wxEVT_COMBOBOX, &HypcroFrame::OnMinimizeChange, this); // Bind event handler
    m_minimizeDropdown->SetValue("Disabled"); // Initial value
    m_minimizeVar = "Disabled"; // Sync internal state
    topSizer->Add(m_minimizeDropdown, 0, wxALIGN_CENTER_VERTICAL | wxLEFT | wxRIGHT, 5);

    mainSizer->Add(topSizer, 0, wxALIGN_CENTER | wxTOP, 10);

    // Mode Selection Dropdown
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Toggle Mode:"), 0, wxALIGN_CENTER | wxTOP, 5);
    wxArrayString toggleModeChoices;
    toggleModeChoices.Add("Smart Mode");
    toggleModeChoices.Add("Toggle Mode");
    toggleModeChoices.Add("Hold Mode");
    m_toggleModeDropdown = new wxComboBox(this, wxID_ANY, "Smart Mode", wxDefaultPosition, wxDefaultSize, toggleModeChoices, wxCB_READONLY);
    m_toggleModeDropdown->Bind(wxEVT_COMBOBOX, &HypcroFrame::OnToggleModeChange, this); // Bind event handler
    m_toggleModeDropdown->SetValue("Smart Mode"); // Initial value
    m_toggleModeVar = "Smart Mode"; // Sync internal state
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_toggle_mode = "Smart Mode"; // Sync global state
    }
    mainSizer->Add(m_toggleModeDropdown, 0, wxALIGN_CENTER | wxEXPAND | wxLEFT | wxRIGHT, 20);

    // Choose Type Dropdown
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Toggle Type:"), 0, wxALIGN_CENTER | wxTOP, 5);
    wxArrayString typeChoices;
    typeChoices.Add("Diagonal");
    typeChoices.Add("Horizontal");
    m_typeDropdown = new wxComboBox(this, wxID_ANY, "Diagonal", wxDefaultPosition, wxDefaultSize, typeChoices, wxCB_READONLY);
    m_typeDropdown->Bind(wxEVT_COMBOBOX, &HypcroFrame::OnTypeChange, this); // Bind event handler
    m_typeDropdown->SetValue("Diagonal"); // Initial value
    m_typeVar = "Diagonal"; // Sync internal state
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_selected_type = "Diagonal"; // Sync global state
    }
    mainSizer->Add(m_typeDropdown, 0, wxALIGN_CENTER | wxEXPAND | wxLEFT | wxRIGHT, 20);

    // Select Direction Dropdown
    mainSizer->Add(new wxStaticText(this, wxID_ANY, "Select Direction:"), 0, wxALIGN_CENTER | wxTOP, 5);
    wxArrayString directionChoices;
    directionChoices.Add("Left");
    directionChoices.Add("Right");
    m_directionDropdown = new wxComboBox(this, wxID_ANY, "Right", wxDefaultPosition, wxDefaultSize, directionChoices, wxCB_READONLY);
    m_directionDropdown->Bind(wxEVT_COMBOBOX, &HypcroFrame::OnDirectionChange, this); // Bind event handler
    m_directionDropdown->SetValue("Right"); // Initial value
    m_directionVar = "Right"; // Sync internal state
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_selected_side = "Right"; // Sync global state
    }
    mainSizer->Add(m_directionDropdown, 0, wxALIGN_CENTER | wxEXPAND | wxLEFT | wxRIGHT, 20);

    // Hotkey Bind UI
    wxBoxSizer* hotkeySizer = new wxBoxSizer(wxHORIZONTAL);
    m_changeBindBtn = new wxButton(this, wxID_ANY, "Change Bind");
    m_changeBindBtn->Bind(wxEVT_BUTTON, &HypcroFrame::OnChangeBindClick, this); // Bind event handler
    hotkeySizer->Add(m_changeBindBtn, 0, wxALIGN_CENTER_VERTICAL | wxRIGHT, 8);

    m_currentHotkeyVar = "X"; // Initial value
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_current_hotkey = "X"; // Sync global state
    }
    m_hotkeyLabel = new wxStaticText(this, wxID_ANY, "");
    hotkeySizer->Add(m_hotkeyLabel, 0, wxALIGN_CENTER_VERTICAL);
    UpdateHotkeyLabel(); // Set initial label text

    mainSizer->Add(hotkeySizer, 0, wxALIGN_CENTER | wxTOP, 10);

    // Status Label
    wxBoxSizer* statusSizer = new wxBoxSizer(wxHORIZONTAL);
    wxStaticText* statusText = new wxStaticText(this, wxID_ANY, "Status: ");
    statusText->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    statusSizer->Add(statusText, 0, wxALIGN_CENTER_VERTICAL);

    m_statusWord = new wxStaticText(this, wxID_ANY, "OFF");
    m_statusWord->SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
    m_statusWord->SetForegroundColour(*wxRED);
    statusSizer->Add(m_statusWord, 0, wxALIGN_CENTER_VERTICAL);

    mainSizer->Add(statusSizer, 0, wxALIGN_CENTER | wxTOP | wxBOTTOM, 10);

    // Always On Top Checkbox
    m_alwaysOnTopCheckbox = new wxCheckBox(this, wxID_ANY, "Always On Top");
    m_alwaysOnTopCheckbox->Bind(wxEVT_CHECKBOX, &HypcroFrame::OnAlwaysOnTopToggle, this); // Bind event handler
    mainSizer->Add(m_alwaysOnTopCheckbox, 0, wxALIGN_CENTER | wxBOTTOM, 0);

    // Finalize sizer layout
    mainSizer->Layout();
    mainSizer->Fit(this); // Adjust frame size to fit controls

    // Get window handle for minimize/restore (Windows specific)
#ifdef _WIN32
    m_appWindow = (HWND)GetHandle();
#endif

    // Start the background key listener thread
#ifdef _WIN32
    StartKeyListener();
#endif

    // Bind the custom hook event handler
    Bind(wxEVT_HOOK_EVENT, &HypcroFrame::OnHookEvent, this);

    Centre(); // Center the window
    Show(true); // Show the window
}

HypcroFrame::~HypcroFrame() {
    // Stop the background key listener thread
#ifdef _WIN32
    StopKeyListener();
    StopBindListener(); // Ensure bind listener is stopped if active
#endif
}

// --- Event Handler Implementations ---

void HypcroFrame::OnStatusChange(wxCommandEvent& event) {
    wxString selected = m_statusDropdown->GetValue();
    m_statusVar = selected; // Sync internal state

    bool enabled = (selected == "ON");
    g_app_enabled.store(enabled); // Sync global state

    UpdateStatusLabel();
    MinimizeIfNeeded(enabled);

    // Reset toggle state when turning OFF
    if (!enabled) {
        g_toggle.store(false);
        g_hold_mode.store(false);
        g_x_is_held.store(false);
        g_smart_held.store(false);
        // Ensure keys are released if app is turned off while active
        ProcessKeyRelease(this);
    }
}

void HypcroFrame::OnMinimizeChange(wxCommandEvent& event) {
    wxString selected = m_minimizeDropdown->GetValue();
    m_minimizeVar = selected; // Sync internal state

    // If auto minimize is enabled, uncheck always on top
    if (m_minimizeVar == "Enabled") {
        m_alwaysOnTopCheckbox->SetValue(false);
        m_alwaysOnTopVar = false; // Sync internal state
        SetWindowStyleFlag(GetWindowStyleFlag() & ~wxSTAY_ON_TOP); // Remove always on top style
        // Re-enable minimize dropdown if it was disabled by Always On Top
        m_minimizeDropdown->Enable(true);
    }
    // Note: MinimizeIfNeeded is called by OnStatusChange or hook handlers
    // based on the current state, which now reflects the new minimizeVar.
}

void HypcroFrame::OnAlwaysOnTopToggle(wxCommandEvent& event) {
    m_alwaysOnTopVar = m_alwaysOnTopCheckbox->GetValue(); // Sync internal state

    if (m_alwaysOnTopVar) {
        // If Always On Top is checked, disable auto minimize
        m_minimizeVar = "Disabled"; // Sync internal state
        m_minimizeDropdown->SetValue("Disabled"); // Update dropdown
        m_minimizeDropdown->Enable(false); // Disable dropdown
        SetWindowStyleFlag(GetWindowStyleFlag() | wxSTAY_ON_TOP); // Set always on top style
    } else {
        m_minimizeDropdown->Enable(true); // Re-enable dropdown
        SetWindowStyleFlag(GetWindowStyleFlag() & ~wxSTAY_ON_TOP); // Remove always on top style
    }
    // Apply the style change
    Layout(); // Needed to apply style changes sometimes
}

void HypcroFrame::OnToggleModeChange(wxCommandEvent& event) {
    wxString selected = m_toggleModeDropdown->GetValue();
    m_toggleModeVar = selected; // Sync internal state
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_toggle_mode = selected.ToStdString(); // Sync global state
    }
    // Reset state when mode changes
    g_toggle.store(false);
    g_hold_mode.store(false);
    g_x_is_held.store(false);
    g_smart_held.store(false);
    UpdateStatusLabel();
    MinimizeIfNeeded(false); // Ensure window is restored if it was minimized by the old mode
    ProcessKeyRelease(this); // Ensure keys are released
}

void HypcroFrame::OnTypeChange(wxCommandEvent& event) {
    wxString selected = m_typeDropdown->GetValue();
    m_typeVar = selected; // Sync internal state
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_selected_type = selected.ToStdString(); // Sync global state
    }
}

void HypcroFrame::OnDirectionChange(wxCommandEvent& event) {
    wxString selected = m_directionDropdown->GetValue();
    m_directionVar = selected; // Sync internal state
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        g_selected_side = selected.ToStdString(); // Sync global state
    }
}

void HypcroFrame::OnChangeBindClick(wxCommandEvent& event) {
    // Temporarily disable app and start binding listener
    wxString prev_state = m_statusVar;
    m_statusVar = "OFF";
    m_statusDropdown->SetValue("OFF");
    g_app_enabled.store(false); // Sync global state
    g_is_binding.store(true); // Sync global state

    UpdateStatusLabel();
    UpdateHotkeyLabel();

    m_statusDropdown->Enable(false); // Disable Able toggle dropdown

#ifdef _WIN32
    StartBindListener(); // Start the temporary hook for binding
#endif
}

// Handler for custom hook events posted from the hook thread
void HypcroFrame::OnHookEvent(wxCommandEvent& event) {
    HookEventData* data = reinterpret_cast<HookEventData*>(event.GetClientData());
    if (!data) return;

    DWORD vkCode = data->vkCode;
    bool isPress = data->isPress;
    delete data; // Free the allocated data

    // Convert VK code back to char (basic)
    char keyChar = MapVirtualKeyA(vkCode, MAPVK_VKCODE_TO_CHAR);
    if (keyChar == 0) {
        // Handle special keys if needed, but original only handled printable chars
        return;
    }
    keyChar = toupper(keyChar);

    std::string currentHotkey;
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        currentHotkey = g_current_hotkey;
    }

    // --- Binding Logic (if in binding mode) ---
    if (g_is_binding.load()) {
        if (isPress) {
            // Capture the pressed key as the new hotkey
            m_currentHotkeyVar = wxString(keyChar); // Sync internal state
            {
                std::lock_guard<std::mutex> lock(g_state_mutex);
                g_current_hotkey = m_currentHotkeyVar.ToStdString(); // Sync global state
            }

            g_is_binding.store(false); // Exit binding mode
            UpdateHotkeyLabel();

            // Restore previous status
            wxString prev_state = m_statusDropdown->GetValue(); // Get current value before re-enabling
            m_statusDropdown->Enable(true); // Re-enable Able toggle dropdown
            // Note: OnStatusChange will be called if the user changes the dropdown value later.
            // We don't automatically restore the *previous* state here, just re-enable the control.
            // The Python code also just re-enabled the dropdown, it didn't automatically set it back.

#ifdef _WIN32
            StopBindListener(); // Stop the temporary hook
#endif
        }
        return; // Don't process as a hotkey press/release while binding
    }

    // --- Hotkey Logic (if not binding and app is enabled) ---
    if (!g_app_enabled.load()) {
        return;
    }

    // Check if the pressed/released key is the current hotkey
    if (keyChar == toupper(currentHotkey[0])) { // Assuming hotkey is a single character
        std::string mode;
        {
            std::lock_guard<std::mutex> lock(g_state_mutex);
            mode = g_toggle_mode;
        }

        if (isPress) {
            if (g_x_is_held.load()) {
                return; // Already held, ignore repeat press
            }
            g_x_is_held.store(true);

            if (mode == "Hold Mode") {
                g_hold_mode.store(true);
                UpdateStatusLabel();
                MinimizeIfNeeded(true);
                ProcessKeyPress(this);
            } else if (mode == "Toggle Mode") {
                auto currentTime = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - g_last_toggle_time.load()).count();
                if (elapsed > 0.2) {
                    bool currentToggle = g_toggle.load();
                    g_toggle.store(!currentToggle);
                    UpdateStatusLabel();
                    MinimizeIfNeeded(g_toggle.load());
                    if (g_toggle.load()) {
                        ProcessKeyPress(this);
                    } else {
                        ProcessKeyRelease(this);
                    }
                    g_last_toggle_time.store(currentTime);
                }
            } else if (mode == "Smart Mode") {
                {
                    std::lock_guard<std::mutex> lock(g_smart_mode_mutex);
                    g_smart_press_time = std::chrono::high_resolution_clock::now();
                    g_smart_held.store(false); // Assume not held initially
                }

                // Start the hold check thread if not already running
                if (!g_smart_check_running.load()) {
                    g_smart_check_running.store(true);
                    std::thread(&HypcroFrame::CheckHold, this).detach(); // Detach the thread
                }
            }
        } else { // isRelease
            if (!g_x_is_held.load()) {
                return; // Not held, ignore release
            }
            g_x_is_held.store(false);

            if (mode == "Hold Mode") {
                if (g_hold_mode.load()) {
                    g_hold_mode.store(false);
                    UpdateStatusLabel();
                    MinimizeIfNeeded(false);
                    ProcessKeyRelease(this);
                }
            } else if (mode == "Toggle Mode") {
                // Nothing to do on release in Toggle Mode
            } else if (mode == "Smart Mode") {
                auto currentTime = std::chrono::high_resolution_clock::now();
                std::chrono::high_resolution_clock::time_point pressTime;
                bool wasHeld;
                {
                    std::lock_guard<std::mutex> lock(g_smart_mode_mutex);
                    pressTime = g_smart_press_time;
                    wasHeld = g_smart_held.load();
                    // Reset smart mode state on release
                    g_smart_press_time = std::chrono::high_resolution_clock::time_point(); // Reset time
                    g_smart_held.store(false);
                }

                if (pressTime != std::chrono::high_resolution_clock::time_point()) { // Check if press time was recorded
                    auto elapsed = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - pressTime).count();

                    if (wasHeld) {
                        UpdateStatusLabel();
                        MinimizeIfNeeded(false);
                        ProcessKeyRelease(this);
                    } else {
                        // This is a short press (toggle)
                        auto lastToggleElapsed = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - g_last_toggle_time.load()).count();
                        if (lastToggleElapsed > 0.2) {
                            bool currentToggle = g_toggle.load();
                            g_toggle.store(!currentToggle);
                            UpdateStatusLabel();
                            MinimizeIfNeeded(g_toggle.load());
                            if (g_toggle.load()) {
                                ProcessKeyPress(this);
                            } else {
                                ProcessKeyRelease(this);
                            }
                            g_last_toggle_time.store(currentTime);
                        }
                    }
                }
                // Signal the check_hold thread to stop if it's running
                // (The thread checks g_x_is_held)
            }
        }
    }
}


// --- Helper Function Implementations ---

void HypcroFrame::UpdateStatusLabel() {
    bool enabled = g_app_enabled.load();
    bool active = false; // Represents if actions are currently being performed

    std::string mode;
    {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        mode = g_toggle_mode;
    }

    if (enabled) {
        if (mode == "Hold Mode") {
            active = g_hold_mode.load();
        } else if (mode == "Toggle Mode") {
            active = g_toggle.load();
        } else if (mode == "Smart Mode") {
            active = g_smart_held.load() || g_toggle.load(); // Active if held OR toggled ON
        }
    }

    if (active) {
        m_statusWord->SetLabel("ON");
        m_statusWord->SetForegroundColour(*wxGREEN);
    } else {
        m_statusWord->SetLabel("OFF");
        m_statusWord->SetForegroundColour(*wxRED);
    }
    m_statusWord->Refresh(); // Ensure label updates
}

void HypcroFrame::UpdateHotkeyLabel() {
    if (g_is_binding.load()) {
        m_hotkeyLabel->SetLabel("[default X]Hotkey: Binding");
    } else {
        std::lock_guard<std::mutex> lock(g_state_mutex);
        m_hotkeyLabel->SetLabel(wxString::Format("[default X]Hotkey: %s", g_current_hotkey.c_str()));
    }
    m_hotkeyLabel->Refresh(); // Ensure label updates
}

void HypcroFrame::MinimizeIfNeeded(bool state) {
    // Does nothing if Always On Top is enabled
    if (m_alwaysOnTopVar) {
        return;
    }

    // Only minimize/restore if Auto Minimize is Enabled
    if (m_minimizeVar == "Enabled") {
#ifdef _WIN32
        if (m_appWindow != NULL) {
            bool isMinimized = IsIconic(m_appWindow);
            if (state) { // Should be minimized
                if (!isMinimized) {
                    ShowWindow(m_appWindow, SW_MINIMIZE);
                }
            } else { // Should be restored
                if (isMinimized) {
                    ShowWindow(m_appWindow, SW_RESTORE);
                    // Force window size after restore (similar to Python's after call)
                    // Use wxTimer or wxCallAfter for GUI thread safety
                    wxCallAfter([this]() {
                        SetSize(400, 250);
                    });
                }
            }
        }
#endif
    }
}

// Smart Mode Hold Check Thread Function
void HypcroFrame::CheckHold() {
    std::this_thread::sleep_for(std::chrono::milliseconds(220)); // Wait 0.22 seconds

    // Check if the key is still held and we haven't already registered it as held
    if (g_x_is_held.load() && !g_smart_held.load()) {
        {
            std::lock_guard<std::mutex> lock(g_smart_mode_mutex);
            g_smart_held.store(true); // Register as held
        }
        // Post message to GUI thread to update status and process press
        HookEventData* data = new HookEventData();
        data->vkCode = CharToVkCode(g_current_hotkey[0]); // Pass the hotkey VK code
        data->isPress = true; // Treat as a "hold press" event for processing
        wxCommandEvent event(wxEVT_HOOK_EVENT, GetId());
        event.SetClientData(data);
        wxPostEvent(this, event);
    }
    g_smart_check_running.store(false); // Allow a new check thread to start next time
}


// --- Windows Hook Implementation ---

#ifdef _WIN32

// Low-Level Keyboard Hook Procedure for main listener
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pkh = (KBDLLHOOKSTRUCT*)lParam;
        bool isPress = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN);
        bool isRelease = (wParam == WM_KEYUP || wParam == WM_SYSKEYUP);

        if (isPress || isRelease) {
            // Post message to the GUI thread
            HookEventData* data = new HookEventData();
            data->vkCode = pkh->vkCode;
            data->isPress = isPress;

            // Find the main application window by title
            // Note: Finding the window handle repeatedly in the hook might be inefficient.
            // A better approach is to pass the handle to the hook procedure or store it globally.
            // For simplicity matching Python structure, we find it here.
            // A more robust C++ solution would pass the frame pointer or handle.
            // Let's find the window by class name or title.
            // Assuming the wxFrame title is "HypcroV2"
            HWND hWnd = FindWindowW(NULL, L"HypcroV2"); // Use wide string for title
            if (hWnd) {
                // Post the custom event to the frame
                wxCommandEvent event(wxEVT_HOOK_EVENT, wxID_ANY); // Use wxID_ANY or a specific ID if needed
                event.SetClientData(data);
                // wxPostEvent requires a wxEvtHandler. We need to get the wxFrame instance.
                // This is tricky from a raw WinAPI hook.
                // A common pattern is to store the wxFrame pointer globally or in the hook data.
                // Let's assume we can get the wxFrame instance from the HWND.
                // wxWidgets provides wxWindow::FindFromHWND.
                wxWindow* window = wxWindow::FindFromHWND(hWnd);
                if (window) {
                    wxEvtHandler* handler = window->GetEventHandler();
                    if (handler) {
                         // Need to ensure the event ID matches the one bound in the frame
                         // Let's use a fixed ID or pass it. Using wxID_ANY in Bind and PostEvent might work.
                         // Let's define a specific custom event ID.
                         // wxDEFINE_EVENT(wxEVT_HOOK_EVENT, wxCommandEvent); defined globally
                         event.SetEventType(wxEVT_HOOK_EVENT);
                         handler->AddPendingEvent(event); // Use AddPendingEvent for thread safety
                    } else {
                         delete data; // Clean up if handler not found
                    }
                } else {
                    delete data; // Clean up if window not found
                }
            } else {
                 delete data; // Clean up if window handle not found
            }
        }
    }
    // Pass the event to the next hook in the chain
    return CallNextHookEx(g_keyboard_hook, nCode, wParam, lParam);
}

// Low-Level Keyboard Hook Procedure for binding
LRESULT CALLBACK BindKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    if (nCode == HC_ACTION) {
        KBDLLHOOKSTRUCT* pkh = (KBDLLHOOKSTRUCT*)lParam;
        bool isPress = (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN);

        if (isPress) {
            // Post message to the GUI thread
            HookEventData* data = new HookEventData();
            data->vkCode = pkh->vkCode;
            data->isPress = true; // Only care about press for binding

            // Find the main application window
            HWND hWnd = FindWindowW(NULL, L"HypcroV2");
            if (hWnd) {
                wxWindow* window = wxWindow::FindFromHWND(hWnd);
                if (window) {
                    wxEvtHandler* handler = window->GetEventHandler();
                    if (handler) {
                         wxCommandEvent event(wxEVT_HOOK_EVENT, wxID_ANY);
                         event.SetClientData(data);
                         event.SetEventType(wxEVT_HOOK_EVENT);
                         handler->AddPendingEvent(event);
                    } else {
                         delete data;
                    }
                } else {
                    delete data;
                }
            } else {
                 delete data;
            }

            // Stop the bind hook after capturing one key
            // This needs to happen *after* the message is posted,
            // but stopping the hook from inside the hook proc is complex/risky.
            // A better way is to signal the hook thread to stop its message loop.
            // For simplicity here, we'll let the hook continue until StopBindListener is called.
            // The GUI thread will call StopBindListener after processing the event.
        }
    }
    // Pass the event to the next hook in the chain
    return CallNextHookEx(g_bind_hook, nCode, wParam, lParam);
}


// Thread function for the main keyboard listener hook
void KeyboardHookThread() {
    g_hook_thread_id = GetCurrentThreadId();
    g_keyboard_hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, NULL, 0);

    if (!g_keyboard_hook) {
        wxLogError("Failed to install keyboard hook!");
        return;
    }

    // Message loop required for hooks
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook when the loop ends (e.g., thread is signaled to stop)
    UnhookWindowsHookEx(g_keyboard_hook);
    g_keyboard_hook = NULL;
    g_hook_thread_id = 0;
}

// Thread function for the bind keyboard listener hook
void BindKeyboardHookThread() {
    g_bind_hook_thread_id = GetCurrentThreadId();
    g_bind_hook = SetWindowsHookEx(WH_KEYBOARD_LL, BindKeyboardProc, NULL, 0);

    if (!g_bind_hook) {
        wxLogError("Failed to install bind keyboard hook!");
        return;
    }

    // Message loop required for hooks
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // Unhook when the loop ends
    UnhookWindowsHookEx(g_bind_hook);
    g_bind_hook = NULL;
    g_bind_hook_thread_id = 0;
}


void HypcroFrame::StartKeyListener() {
    if (!g_hook_thread.joinable()) {
        g_hook_thread = std::thread(KeyboardHookThread);
        // The thread will run the hook and its message loop
    }
}

void HypcroFrame::StopKeyListener() {
    if (g_hook_thread.joinable()) {
        // Signal the hook thread to exit its message loop
        if (g_hook_thread_id != 0) {
            PostThreadMessage(g_hook_thread_id, WM_QUIT, 0, 0);
        }
        g_hook_thread.join(); // Wait for the thread to finish
    }
}

void HypcroFrame::StartBindListener() {
    if (!g_bind_hook_thread.joinable()) {
        g_bind_hook_thread = std::thread(BindKeyboardHookThread);
        // The thread will run the hook and its message loop
    }
}

void HypcroFrame::StopBindListener() {
    if (g_bind_hook_thread.joinable()) {
        // Signal the bind hook thread to exit its message loop
        if (g_bind_hook_thread_id != 0) {
            PostThreadMessage(g_bind_hook_thread_id, WM_QUIT, 0, 0);
        }
        g_bind_hook_thread.join(); // Wait for the thread to finish
    }
}

#else // Non-Windows placeholder implementations
void HypcroFrame::StartKeyListener() { wxLogWarning("Keyboard listener not implemented for this platform."); }
void HypcroFrame::StopKeyListener() {}
void HypcroFrame::StartBindListener() { wxLogWarning("Hotkey binding not implemented for this platform."); }
void HypcroFrame::StopBindListener() {}
void ProcessKeyPress(HypcroFrame* frame) { wxLogWarning("Input simulation not implemented for this platform."); }
void ProcessKeyRelease(HypcroFrame* frame) { wxLogWarning("Input simulation not implemented for this platform."); }
void HypcroFrame::MinimizeIfNeeded(bool state) { wxLogWarning("Window minimize/restore not implemented for this platform."); }
void HypcroFrame::CheckHold() { wxLogWarning("Smart mode hold check not implemented for this platform."); }
#endif


// --- wxWidgets Application Class ---

class HypcroApp : public wxApp {
public:
    virtual bool OnInit();
    virtual int OnExit();
};

IMPLEMENT_APP(HypcroApp);

bool HypcroApp::OnInit() {
    // Create the main application frame
    HypcroFrame* frame = new HypcroFrame("HypcroV2");
    // The frame constructor handles showing the window and starting the listener

    return true;
}

int HypcroApp::OnExit() {
    // Clean up resources if needed
    // The frame destructor should handle stopping the listener thread
    return wxApp::OnExit();
}
