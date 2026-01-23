#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DECODE.INP", "r", stdin);
    freopen("DECODE.OUT", "w", stdout);

    string s;
    cin >> s;

    map<string, char> mp = {
        {"a", '1'},
        {"b", '2'},
        {"cc", '3'},
        {"bbc", '4'},
        {"cbc", '5'},
        {"abc", '6'},
        {"bac", '7'},
        {"aac", '8'},
        {"cac", '9'}
    };

    string res = "";
    int i = s.size();

    while (i > 0) {
        bool found = false;
        for (int len = 3; len >= 1; len--) {
            if (i - len >= 0) {
                string sub = s.substr(i - len, len);
                if (mp.count(sub)) {
                    res = mp[sub] + res;
                    i -= len;
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            cout << -1;
            return 0;
        }
    }

    cout << res;
    return 0;
}
