#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PHANMAY.INP", "r", stdin);
    freopen("PHANMAY.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0, cur = 0, ans = 0;
    while (i < n && j < n) {
        if (a[i] < b[j]) {
            cur++;
            ans = max(ans, cur);
            i++;
        } else {
            cur--;
            j++;
        }
    }
    cout << ans << '\n';
    return 0;
}
