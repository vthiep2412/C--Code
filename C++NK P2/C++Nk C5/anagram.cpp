#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("ANAGRAM.INP", "r", stdin);
    freopen("ANAGRAM.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        if (s.size() % 2 != 0) {
            cout << -1 << "\n";
            continue;
        }

        int mid = s.size() / 2;
        string x = s.substr(0, mid);
        string y = s.substr(mid);
        vector<int> freq(26, 0);
        for (char c : x) {
            freq[c - 'a']++;
        }
        for (char c : y) {
            freq[c - 'a']--;
        }
        int substitutions = 0;
        for (int count : freq) {
            if (count > 0) {
                substitutions += count;
            }
        }
        cout << substitutions << "\n";
    }
    return 0;
}