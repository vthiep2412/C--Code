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
    freopen("mang10.inp", "r", stdin);
    freopen("mang10.out", "w", stdout);
    ll n,m;
    cin>>n>>m;
    m%=n;
    vc<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll i=0;i<m;i++){
        a.push_back(a[i]); 
    }
    // ll fst=0,lst=n-1;
    // for(ll i=0;i<m;i++){
    //     ll x = a[fst];
    //     a.push_back(x);
    //     fst++;
    //     lst++;
    // }
    for(ll i=m;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}