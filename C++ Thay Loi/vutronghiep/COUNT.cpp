#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll demuoc(ll n){
    ll cnt=0;
    for(ll i=1;i*i<=n;++i){
        if(n%i==0){
            cnt++;
            if(i*i!=n) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("count.inp", "r", stdin);
    freopen("count.out", "w", stdout);
    ll n,x,maxuoc=0;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>x;
        maxuoc=max(maxuoc,demuoc(x));
    }
    cout<<maxuoc;
    return 0;
}