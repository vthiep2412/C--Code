#include <bits/stdc++.h>
using namespace std;

struct e {
    int a=0,b=0,c=0;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("PAINT.INP", "r")){
        freopen("PAINT.INP", "r", stdin);
        freopen("PAINT.OUT", "w", stdout);
    }

    int t,n;
    cin >> t;
    while (t--) {
        cin>>n;
        int a,b,c;
        vector<e> dp(n+1);
        for(int i=1;i<=n;i++){
            cin>>a>>b>>c;
            dp[i].a = a + min(dp[i-1].b, dp[i-1].c);
            dp[i].b = b + min(dp[i-1].a, dp[i-1].c);
            dp[i].c = c + min(dp[i-1].b, dp[i-1].a);
        }
        cout << min({dp[n].a, dp[n].b, dp[n].c}) << "\n";
    }
    return 0;
}