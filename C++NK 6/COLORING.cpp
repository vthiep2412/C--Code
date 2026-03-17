#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set 
#define umap unordered_map 

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("COLORING.inp", "r", stdin);
    freopen("COLORING.out", "w", stdout);
    ll n,m;
    ll R=0,G=0,B=0;
    uset<ll> ans;
    cin >> n >> m;
    ll maxi = max(n,m);
    ll mini = min(n,m);
    for(ll i=1;i<=maxi;i++){
        for(ll j=1;j<=mini;j++){
            ll x = i * j;
            // cout<<x<<endl;
            if (x % 5 == 0) B++;
            else if (x % 3 == 0) G++;
            else if (x % 2 == 0) R++;
        } 
    }
    cout << R << "\n" << G << "\n" << B << "\n" << n*m - (R + G + B);
    return 0;
}