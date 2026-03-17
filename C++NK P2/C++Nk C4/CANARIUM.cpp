#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

void solve(ll nn){
    ll k = 2*nn;
    pair<ll,ll> res = {1e14,-1};
    for(ll m = 1;m*(m+1)<=k;m++){
        ll n = (k - m -1)/(2*m+1);
        if(abs(n-m)<abs(res.first-res.second)){
            if((m*n)+(m+1)*(n+1) == k) res = {m,n};
        }
    }
    if(res.second == -1){
        cout << -1<<" "<<-1<<"\n";
    }else{
        cout<<res.first<<" "<<res.second<<"\n";
    }
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CANARIUM.inp", "r", stdin);
    freopen("CANARIUM.out", "w", stdout);
    ll nn;
    while(cin>>nn){
        solve(nn);
    }
    return 0;
}