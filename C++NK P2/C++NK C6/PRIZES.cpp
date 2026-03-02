#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PRIZES.INP", "r", stdin);
    freopen("PRIZES.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<ll> p(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        p[i] = p[i - 1] + a;
    }

    int m = n - k + 1;
    vector<ll> preMax(m + 2, 0);
    for (int i = 1; i <= m; i++) {
        preMax[i] = max(preMax[i - 1], p[i + k - 1] - p[i - 1]);
    }

    vector<ll> sufMax(m + 2, 0);
    for (int i = m; i >= 1; i--) {
        sufMax[i] = max(sufMax[i + 1], p[i + k - 1] - p[i - 1]);
    }

    ll res = -1;
    for (int i = 1; i <= m; i++) {
        ll steveBest = 0;
        if (i - k >= 1) steveBest = max(steveBest, preMax[i - k]);
        if (i + k <= m) steveBest = max(steveBest, sufMax[i + k]);

        if (res == -1 || steveBest < res) res = steveBest;
    }

    cout << res << "\n";

    return 0;
}