#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("DAYCON.INP", "r", stdin);
    // freopen("DAYCON.OUT", "w", stdout);

    int n, s;
    cin >> n >> s;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;

    cerr << "=== DEBUG: BAT DAU XAY DUNG DP ===\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= s; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= a[i] && dp[i-1][j - a[i]]) dp[i][j] = true;
        }

        cerr << "i = " << i << " (phan tu " << a[i] << "): ";
        for (int j = 0; j <= s; j++) {
            if (dp[i][j]) cerr << j << " ";
        }
        cerr << "\n";
    }

    cerr << "=== KET THUC ===\n";
    cout << (dp[n][s] ? "YES\n" : "NO\n");
    return 0;
}
