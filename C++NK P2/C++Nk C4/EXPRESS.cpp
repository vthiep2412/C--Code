#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("EXPRESS.inp", "r", stdin);
    freopen("EXPRESS.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long res = a[0];
    vector<long long> b(a.begin() + 1, a.end());
    sort(b.begin(), b.end(), greater<long long>());
    for (int i = 0; i < b.size(); i++) {
        if (i < k) 
            res += b[i];
        else 
            res -= b[i];
    }
    cout << res << "\n";
    return 0;
}
