#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("BAI3.INP", "r", stdin);
    // freopen("BAI3.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int mn = *min_element(a.begin(), a.end());
    int mx = *max_element(a.begin(), a.end());

    int lastMin = -1, lastMax = -1, ans = n + 1;

    for (int i = 0; i < n; i++) {
        if (a[i] == mn) {
            lastMin = i;
            if (lastMax != -1) ans = min(ans, i - lastMax + 1);
        }
        if (a[i] == mx) {
            lastMax = i;
            if (lastMin != -1) ans = min(ans, i - lastMin + 1);
        }
    }

    cout << ans;
    return 0;
}
