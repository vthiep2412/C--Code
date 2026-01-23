#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ESUM.inp", "r", stdin);
    freopen("ESUM.out", "w", stdout);
    ll n,E=0,O=0,x,cnt=0;
    cin>>n;
    for(ll i=0;i<n;++i){
        cin>>x;
        if(x%2==0) E++;
        else O++;
    }
    if(O%2==0){
        cnt+=(O*(O-1))/2;
        // cout<<cnt<<"   eeeee        \n";
    } else {
        cnt+=((O-1)*(O-2))/2;
        // cout<<cnt<<"   eeeee2        \n";
        cnt+=E;
        // cout<<cnt<<"   eeeee3        \n";
    }
    cnt+=(E*(E-1))/2;
    cout<<cnt;
    return 0;
}