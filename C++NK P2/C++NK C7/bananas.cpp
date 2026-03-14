#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

ll a[205][105], dp[205][105];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("bananas.inp", "r", stdin);
    //freopen("bananas.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0; i<=2*n; i++) 
            for(int j=0; j<=n+1; j++) 
                dp[i][j] = 0;

        for(int i=1; i<=2*n-1; i++){
            int c = (i <= n) ? i : 2*n-i;
            for(int j=1; j<=c; j++) 
                cin>>a[i][j];
        }
        dp[1][1] = a[1][1];
        for(int i=2; i<=n; i++) 
            for(int j=1; j<=i; j++) 
                dp[i][j] = a[i][j] + max(dp[i-1][j-1], dp[i-1][j]);

        for(int i=n+1; i<=2*n-1; i++)
            for(int j=1; j<= 2*n-i; j++) 
                dp[i][j] = a[i][j] + max(dp[i-1][j], dp[i-1][j+1]);

        cout << dp[2*n-1][1] << "\n";
    }
    return 0;
}