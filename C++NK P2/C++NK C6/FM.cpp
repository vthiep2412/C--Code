#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if (fopen("FM.INP", "r")) {
        freopen("FM.INP", "r", stdin);
        freopen("FM.OUT", "w", stdout);
    }

    int n;
    long long m;
	cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;z
    int L = 0, R = n - 1;

    while (L < R) {
        if (a[L] + a[R] <= m) {
            ans += (R - L);
            L++;
        } else R--;
    }

    cout << ans << "\n";

    return 0;
}