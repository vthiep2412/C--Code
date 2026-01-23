#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("FirstDPsum.inp", "r", stdin); 
    //freopen("FirstDPsum.out", "w", stdout);
    // first time working with dp
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n),dp(k+1,0);
    for (ll &x : a) cin >> x;
    dp[0] = 1;
    for(ll x:a){
        for(ll i=k;i>=x;i--){
            cout<<"checking "<<i<<" from "<<i-x<<"\n";
            cout<<"dp["<<i-x<<"] = "<<dp[i-x]<<"\n";
            if(dp[i-x]){
                dp[i] = 1;
                cout<<"updated dp["<<i<<"] to 1\n";
            }
            cout<<"\n";
        }
    }
    if(dp[k]) cout<<"YES\n";
    else cout<<"NO\n";
    return 0;
}