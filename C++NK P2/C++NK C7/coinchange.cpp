#include <bits/stdc++.h>
using namespace std;

int main() {
    if (fopen("COINCHANGE.INP", "r")) {
        freopen("COINCHANGE.INP", "r", stdin);
        freopen("COINCHANGE.OUT", "w", stdout);
    }
    int n,m;
    cin>>m>>n;
    vector<int> coins(n), dp(m+1, 0);
    dp[0]=1;
    for(int i=0;i<n;i++) cin>>coins[i];
    for(const int &coin : coins)
        for(int i=coin;i<=m;i++)
            dp[i] += dp[i-coin];
    cout<<dp[m];
    return 0;
}