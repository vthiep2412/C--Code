#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
typedef long long ll;
bool prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("countsnt.inp", "r", stdin);
    freopen("countsnt.out", "w", stdout);
    ll n,max;
    cin >> n;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) {
        cin>>a[i];
        max = std::max(max,a[i]);
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
        if (prime(a[i])) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}