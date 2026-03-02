#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("KTHSUM.INP", "r", stdin);
    freopen("KTHSUM.OUT", "w", stdout);
    ll n,k, l = 0, r = 2e6, ans = r;
    cin >> n >> k;

    vector<ll> a(n);
    for (ll& x : a) cin >> x;
    sort(a.begin(), a.end());

    while (l <= r) {
        ll mid = l + (r - l) / 2;
        ll i = 0, j = n - 1, cnt = 0;

        while (i < j) {
            if (a[i] + a[j] <= mid) {
                cnt += j - i;
                i++;
            } else j--;
        }

        if (cnt >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    cout << ans;
    return 0;
}