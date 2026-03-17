#include <bits/stdc++.h>
using namespace std;

int solve(string s, char target) {
    int n = s.size(), cnt = 0;
    for (int i = 0; i + 3 < n; i++) {
        if (s[i] != target) {
            for (int j = 0; j < 4; j++) {
                s[i + j] = (s[i + j] == '0' ? '1' : '0');
            }
            cnt++;
        }
    }
    for (char c : s) if (c != target) return -1;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BITSTR.INP", "r", stdin);
    freopen("BITSTR.OUT", "w", stdout);

    string s;
    cin >> s;
    int a = solve(s, '0');
    int b = solve(s, '1');
    if (a == -1 && b == -1) cout << -1;
    else if (a == -1) cout << b;
    else if (b == -1) cout << a;
    else cout << min(a, b);
    return 0;
}
