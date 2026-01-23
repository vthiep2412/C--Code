#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0, c1 = 0, c2 = 0;

    if (s.size() % 2 != 0) return false;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') a1++;
        else if (s[i] == ')') a2++;
        else if (s[i] == '[') b1++;
        else if (s[i] == ']') b2++;
        else if (s[i] == '{') c1++;
        else if (s[i] == '}') c2++;
        if (s[i] == ')') {
            size_t pos = s.rfind('(', i);
            if (pos == string::npos) return false;
            s.erase(pos, i - pos + 1);
            i = pos - 1;
        } else if (s[i] == ']') {
            size_t pos = s.rfind('[', i);
            if (pos == string::npos) return false;
            s.erase(pos, i - pos + 1);
            i = pos - 1;
        } else if (s[i] == '}') {
            size_t pos = s.rfind('{', i);
            if (pos == string::npos) return false;
            s.erase(pos, i - pos + 1);
            i = pos - 1;
        }
    }
    return s.empty();
}

int main() {
    cout << boolalpha;
    cout << isValid("abcdefgtijkl") << "\n"; // For debugging; you'll need to pass valid parentheses strings.
    cout << isValid("()[]{}") << "\n";        // Expected: true
    cout << isValid("([)]") << "\n";          // Expected: false
    cout << isValid("([{)") << "\n";
    return 0;
}