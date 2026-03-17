#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define st first
#define nd second

ll numReverse(ll n) {
    ll oi = 0;
    while (n > 0) {
        oi = oi * 10 + n % 10;
        n /= 10;
    }
    return oi;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("NUMFRE.inp", "r", stdin);
    freopen("NUMFRE.out", "w", stdout);
    ll a,b,cnt=0;
    cin >> a >> b;
    for(ll i = a; i <= b; i++) {
        ll x = numReverse(i);
        if(__gcd(i, x) == 1) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}