#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("SQUARE.inp", "r", stdin);
    // freopen("SQUARE.out", "w", stdout);
    int n,m,maxi=0;
    cin >> n>>m;
    vector<vector<char>> a(n,vector<char>(m));
    vector<vector<int>> dp(n,vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(i == 0 or j == 0)
                if(a[i][j] == '*') {dp[i][j]=1; maxi = max(maxi,dp[i][j]);}
                else dp[i][j]=0;
            else if (a[i][j] == '.')
                dp[i][j]=0;
            else {
                dp[i][j] = min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1])) + 1;
                maxi = max(maxi,dp[i][j]);
            }
        }
    
    cout<<maxi;
    return 0;
}

