#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<char, int> led = {
    {'0', 6}, {'1', 2}, {'2', 5}, {'3', 5}, {'4', 4}, 
    {'5', 5}, {'6', 6}, {'7', 3}, {'8', 7}, {'9', 6}
};
int cntled(int hh, int mm) {
    string h = (hh < 10 ? "0" : "") + to_string(hh);
    string m = (mm < 10 ? "0" : "") + to_string(mm);
    return led[h[0]] + led[h[1]] + led[m[0]] + led[m[1]];
}
int main() {
    // freopen("ALARM.INP", "r", stdin);
    // freopen("ALARM.OUT", "w", stdout);
    int n;
    cin >> n;
    if (n > 25) {
        cout << "Impossible" << "\n";
        return 0;
    } else if (n < 8) {
        cout << "Impossible" << "\n";
        return 0; 
    }
    if (n == 25) {
        cout << "00:08" << "\n";
        return 0;
    } else if (n == 8) {
        cout << "11:11" << "\n";
        return 0;
    }
    for (int hh = 0; hh < 24; hh++) {
        for (int mm = 0; mm < 60; mm++) {
            if (cntled(hh, mm) == n) {
                if (hh < 10) cout << "0";
                cout << hh << ":";
                if (mm < 10) cout << "0";
                cout << mm << "\n";
                return 0;
            }
        }
    }
    cout << "Impossible" << "\n";
    return 0;
}