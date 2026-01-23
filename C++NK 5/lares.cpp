#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("lares.inp", "r", stdin);
    freopen("lares.out", "w", stdout);
    long long n, m, k;
    cin >> n >> m >> k;
    long long x = min(m/2,n);
    long long y = (m + n) - (3 * x);
    long long z = ceil((k - y) / 3);
    if (y>=k){
        cout<<x;
        return 0;
    }
    cout<<x-z;
    return 0;
}