
#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

long long max_wire_length(const vector<long long>& a, long long m) {
    long long l = 0, r = *max_element(a.begin(), a.end());
    long long res = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        long long sum = 0;
        for (long long x : a) {
            if (mid > 0) sum += x / mid;
        }
        if (sum >= m && mid > 0) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("wires.inp", "r", stdin);
    freopen("wires.out", "w", stdout);
    long long n, m;
    while (cin >> n >> m) {
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) cin >> a[i];
        cout << max_wire_length(a, m) << "\n";
    }
    return 0;
}