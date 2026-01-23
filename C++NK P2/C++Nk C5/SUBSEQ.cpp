#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SUBSEQ.INP", "r", stdin);
    freopen("SUBSEQ.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<long long> a(n + 1), s(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }

    long long ans = LLONG_MIN;
    long long minS = s[0];
    for (int i = k; i <= n; i++) {
        minS = min(minS, s[i - k]);
        ans = max(ans, s[i] - minS);
    }

    cout << ans << '\n';
    return 0;
}
