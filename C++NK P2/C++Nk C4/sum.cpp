#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("sum.inp", "r", stdin);
    freopen("sum.out", "w", stdout);
    ll s,cnt=0;
    cin >> s;
    vc<pair<ll,ll>> v;
    ll oi = sqrt(2*s);
    for(ll n = oi;n>=1; --n) {
        ll io = (2*s-n*(n-1));
        if(io % (2*n) == 0) {
            ll a = io/(2*n);
            cnt++;
            v.push_back({a,(a+n-1)});
        }
    }
    cout << cnt << "\n";
    for(auto x : v){
        cout << x.first << " " << x.second << "\n";
    }
    return 0;
}