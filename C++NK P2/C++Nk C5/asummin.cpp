#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int binsearch(const vector<pair<ll, int>> &b, ll x) {
    int l = 0, r = b.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (b[mid].first >= x) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    freopen("ASUMMIN.inp", "r", stdin);
    freopen("ASUMMIN.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    vector<pair<ll, int>> b(m);

    for(ll &x : a) cin >> x;
    for(int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i + 1;
    }

    sort(b.begin(), b.end());

    ll min_val = 1e18;
    int res_a = -1, res_b = -1;

    for(int i = 0; i < n; i++) {
        ll target = -a[i];
        int idx = binsearch(b, target);
        if (idx != -1) {
            ll curr = abs(a[i] + b[idx].first);
            if (curr < min_val) {
                min_val = curr;
                res_a = i + 1;
                res_b = b[idx].second;
            }
        }
        int prev = (idx == -1) ? m - 1 : idx - 1;
        if (prev >= 0) {
            ll curr = abs(a[i] + b[prev].first);
            if (curr < min_val) {
                min_val = curr;
                res_a = i + 1;
                res_b = b[prev].second;
            }
        }
    }

    cout << res_a << " " << res_b;
    return 0;
}