#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define umap unordered_map
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("sumx.inp", "r", stdin);
    freopen("sumx.out", "w", stdout);
    ll n,x,cnt=0;
    umap<ll,ll> m;
    cin>>n;
    vector<ll> a(n);
    for(ll i = 0;i<n;++i) cin>>a[i];
    cin>>x;
    for(ll i = 0;i<n;++i) {
        ll diff = x - a[i];
        if(m[diff] > 0){
            cnt+=m[diff];
        }
        m[a[i]]++;
    }
    cout<<cnt<<"\n";
    return 0;
}