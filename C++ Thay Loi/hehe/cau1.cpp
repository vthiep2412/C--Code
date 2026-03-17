#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CAU1.INP", "r", stdin);
    freopen("CAU1.OUT", "w", stdout);

    long long a[4];
    for (int i = 0; i < 4; ++i) {
        if (!(cin >> a[i])) return 0;
    }
    sort(a, a + 4);

    long long ans = a[0] * a[2];
    cout << ans << "\n";
    return 0;
}
