#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("GAME.inp", "r", stdin);
    freopen("GAME.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x:a) cin >> x;

    vector<int> dp(n, INT_MAX);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        for(int j = 1; j <= k; j++){
            if(i + j < n) dp[i+j] = min(dp[i+j], (dp[i] + abs(a[i+j] - a[i])));
        }
    }

    cout << dp[n - 1];
    return 0;
}