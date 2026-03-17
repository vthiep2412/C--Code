#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    long long best = LLONG_MAX;
    int l = 0, r = n - 1;
    while (l < r) {
        long long s = a[l] + a[r];
        best = min(best, llabs(s));
        if (s > 0) {
            r--;
        } else {
            l++;
        }
    }
    cout << best << '\n';
    return 0;
}
