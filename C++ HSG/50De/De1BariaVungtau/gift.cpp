#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("GIFT.INP", "r", stdin);
    freopen("GIFT.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x:a) cin >> x;

    vector<int> dp(n + 1, 2e9);
    dp[0] = -2e9; 
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int x = a[i], tar = x-k;
        int l = 0, r = ans, len = 0;
        
        while (l <= r) {
            int m = (l + r) / 2;
            if (dp[m] <= tar) len = m, l = m + 1;
            else r = m - 1;
        }
        
        dp[len+1] = min(dp[len+1], x);
        ans = max(ans, len+1);
    }

    cout << ans << "\n";

    return 0;
}