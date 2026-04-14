#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("COINCHANGE.INP", "r")) {
        freopen("COINCHANGE.INP", "r", stdin);
        freopen("COINCHANGE.OUT", "w", stdout);
    }
    long long n,m;
    cin>>m>>n;
    vector<long long> coins(n), dp(m+1, 0);
    dp[0]=1;
    for(long long i=0;i<n;i++) cin>>coins[i];
    for(const long long &coin : coins)
        for(long long i=coin;i<=m;i++)
            dp[i] += dp[i-coin];
    cout<<dp[m];
    return 0;
}