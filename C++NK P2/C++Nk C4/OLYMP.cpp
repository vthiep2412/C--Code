#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define vc vector
#define umap unordered_map



ll leftLevelUp (ll k, ll n, ll m){
    ll diff = k - m;
    if(diff<1) return 0;
    return (diff+n-1)/n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("OLYMP.inp", "r", stdin);
    freopen("OLYMP.out", "w", stdout);
    ll c,n,k;
    cin>>n>>c>>k;
    ll nhap1, nhap2,cnt = 0;
    map<ll,ll> map;
    for(int i=0; i<n; i++){
        cin>>nhap1>>nhap2;
        ll lvup = leftLevelUp(k, nhap1, nhap2);
        if(lvup == 0) {
            cnt++;
            continue;
        }
        map[lvup]++;
    }
    for (auto &[lvup, count] : map) {
        while (c >= lvup && count > 0 && lvup > 0) {
            c -= lvup;
            cnt++;
            count--;
        }
        if (c <= 0) break;
    }
    cout<<cnt<<"\n";
    return 0;
}