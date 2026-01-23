#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("gift.inp", "r", stdin);
    freopen("gift.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    vector<int> val, best;

    for (int x : a) {
        int t = x - k, l = 0, r = (int)val.size() - 1, pos = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (val[m] <= t) pos = m, l = m + 1;
            else r = m - 1;
        }
        int cur = (pos == -1 ? 1 : best[pos] + 1);
        if (val.empty() || x > val.back()) {
            val.push_back(x);
            best.push_back(cur);
        } else best.back() = max(best.back(), cur);
    }
    cout << best.back();
}
