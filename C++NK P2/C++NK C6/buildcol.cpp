#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> a(1e5+5);
ll n, m;

bool check(ll X) {
    ll total = 0, l=0, r = n-1;
    ll lMax = 0, rMax = 0;

    while (l <= r) {
        ll hl = std::max(a[l], X);
        ll hr = std::max(a[r], X);

        if (hl < hr) {
            if (hl >= lMax) 
                lMax = hl;
            else total += (lMax - hl);
            l++;
        } else {
            if (hr >= rMax)
                rMax = hr;
            else total += (rMax - hr);
            r--;
        }
        if (total >= m) return true;
    }
    return total >= m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("buildcol.inp", "r", stdin);
    freopen("buildcol.out", "w", stdout);

    cin >> n >> m;

    ll hi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        hi = std::max(hi,a[i]);
    }

    ll lo = 0, ans = -1;
    while (lo <= hi) {
        ll mid = lo + (hi-lo) / 2;
        if (check(mid)) {
            ans = mid;
            lo = mid + 1;
        } else hi = mid - 1;
    }

    cout << ans << "\n";
    return 0;
}