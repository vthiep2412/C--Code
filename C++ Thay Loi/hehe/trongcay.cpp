#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TRONGCAY.INP", "r", stdin);
    freopen("TRONGCAY.OUT", "w", stdout);

    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<int> pos;
    char ch;
    int idx = 0;
    while (idx < n && (cin >> ch)) {
        if (ch != '0' && ch != '1') continue;
        if (ch == '0') pos.push_back(idx + 1);
        ++idx;
    }

    int m = (int)pos.size();
    if (m <= k) {
        cout << 0 << "\n";
        return 0;
    }

    int ans = INT_MAX;
    for (int L = 0; L + k < m; ++L) {
        int R = L + k;
        int midVal = (pos[L] + pos[R]) / 2;
        auto it = lower_bound(pos.begin() + L, pos.begin() + R + 1, midVal);
        int idx1 = int(it - pos.begin());
        if (idx1 >= L && idx1 <= R) {
            int r = max(pos[idx1] - pos[L], pos[R] - pos[idx1]);
            if (r < ans) ans = r;
        }
        if (idx1 - 1 >= L && idx1 - 1 <= R) {
            int r = max(pos[idx1 - 1] - pos[L], pos[R] - pos[idx1 - 1]);
            if (r < ans) ans = r;
        }
    }

    cout << ans << "\n";
    return 0;
}


