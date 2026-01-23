#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
vector<int> memo;
vector<int> coins = {2, 5};

int dp(int x) {
    if (x == 0) return 0;
    if (x < 0) return INF;
    if (memo[x] != -1) return memo[x];

    int res = INF;
    for (int c : coins) {
        res = min(res, dp(x - c));  // CÓ cộng +1
    }
    return memo[x] = res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);

    int maxAmount = 11;
    memo.assign(maxAmount + 1, -1);

    for (int i = 1; i <= maxAmount; ++i) {
        int ans = dp(i);
        if (ans >= INF) cout << "Amount " << i << ": Impossible\n";
        else cout << "Amount " << i << ": " << ans << " coin(s)\n";
    }

    return 0;
}
