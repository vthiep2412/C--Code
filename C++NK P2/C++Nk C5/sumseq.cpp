#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUMSEQ.INP", "r", stdin);
    freopen("SUMSEQ.OUT", "w", stdout);

    ll n, S;
    cin >> n >> S;
    vector<ll> a(n * 2);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        a[i + n] = a[i];
    }

    ll sum = 0, l = 0, pos = -1, len = n + 1;

    for (ll r = 0; r < 2 * n; r++) {
        sum += a[r];
        ll temp = r-l+1;
        while (sum > S || temp > n) {
            sum -= a[l];
            l++;
            temp = r-l+1;
        }

        if (sum == S && temp < len) {
            len = temp;
            pos = (l % n) + 1;
        }
    }

    if (pos == -1) cout << 0;
    else cout << pos << " " << len;

    return 0;
}
