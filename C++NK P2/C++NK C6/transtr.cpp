#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("TRANSTR.INP", "r", stdin);
    freopen("TRANSTR.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string n_str, s;
    cin >> n_str >> s;
    int len = s.length();
    int k = 0;
    for (char c : n_str) {
        k = (k * 10 + (c - '0')) % len;
    }
    string res = s.substr(k) + s.substr(0, k);
    cout << res;
    return 0;
}