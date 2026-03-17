#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CAYTHONG.INP", "r", stdin);
    freopen("CAYTHONG.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sort(b.begin(), b.end());

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        long long x = -a[i];
        auto it = lower_bound(b.begin(), b.end(), x);
        if (it != b.end()) ans = min(ans, llabs(a[i] + *it));
        if (it != b.begin()) {
            --it;
            ans = min(ans, llabs(a[i] + *it));
        }
    }

    cout << ans << "\n";
    return 0;
}
