#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

vector<vector<ll>> a(1005,vector<ll>(1005)), dp(1005,vector<ll>(1005));

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("maxsum.INP", "r")){
        freopen("maxsum.INP", "r", stdin);
        freopen("maxsum.OUT", "w", stdout);
    }
    ll n,m;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++){
            cin>>a[i][j];
        }
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++){
            ll opt1 = dp[i-1][j];
            ll opt2 = dp[i][j-1];
            ll cur  = (a[i][j] % 2 == 0) ? a[i][j] : 0;
            dp[i][j] = cur + max(opt1,opt2);
        }
    cout<<dp[n][m];
    return 0;
}