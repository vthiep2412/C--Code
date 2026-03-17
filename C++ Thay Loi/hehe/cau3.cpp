#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CAU3.INP", "r", stdin);
    freopen("CAU3.OUT", "w", stdout);

    int n;
    if (!(cin >> n)) return 0;

    int cnt1 = 0;
    int got = 0;
    int best = INT_MIN, cur = 0;
    char ch;

    while (got < n && cin >> ch) {
        if (ch != '0' && ch != '1') continue;
        int val = (ch == '1') ? -1 : 1; // 1 => -1, 0 => +1
        if (ch == '1') ++cnt1;

        if (got == 0) { cur = val; best = val; }
        else { cur = max(val, cur + val); best = max(best, cur); }

        ++got;
    }

    if (got != n) {
        cin.clear();
        int x;
        while (got < n && cin >> x) {
            int val = (x == 1) ? -1 : 1;
            if (x == 1) ++cnt1;
            if (got == 0) { cur = val; best = val; }
            else { cur = max(val, cur + val); best = max(best, cur); }
            ++got;
        }
    }

    if (n == 0) { cout << 0 << "\n"; return 0; }

    int ans = cnt1 + best;
    if (cnt1 == n) ans = n - 1;

    cout << ans << "\n";
    return 0;
}
