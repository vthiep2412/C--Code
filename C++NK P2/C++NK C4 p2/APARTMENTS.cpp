
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("APARTMENTS.inp", "r", stdin);
    freopen("APARTMENTS.out", "w", stdout);
    long long n, m, k, cnt = 0;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long i = 0, j = 0;
    while (i < n && j < m) {
        if (b[j] < a[i] - k) {
            j++;
        } else if (b[j] > a[i] + k) {
            i++;
        } else {
            cnt++;
            i++;
            j++;
        }
    }
    cout << cnt << "\n";
    return 0;
}