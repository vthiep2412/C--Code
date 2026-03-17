#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("CHECKPAL.INP", "r", stdin);
    freopen("CHECKPAL.OUT", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;

    vector<int> counts(26, 0);
    for (char c : s) {
        counts[c - 'a']++;
    }

    int odd_counts = 0;
    for (int count : counts) {
        if (count % 2 != 0) {
            odd_counts++;
        }
    }
    if (odd_counts <= 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}