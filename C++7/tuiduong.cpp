#include <bits/stdc++.h>
using namespace std;

int DynProg(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin < 0) break;
            if (dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] < INT_MAX ? dp[amount] : -1;
    // still learning aint good
}

int Greedy(int n) {
    int maxFive = n / 5;
    while (maxFive >= 0) {
        int remaining = n - maxFive * 5;
        if (remaining % 3 == 0) {
            return maxFive + remaining / 3;
        }
        maxFive--;
    }
    return -1;
}

int main() {
    vector<int> coins = {3, 5};
    int n = 0;
    cin >> n;
    int res = Greedy(n);
    if (res != -1) {
        cout << res;
    }
    else {
        cout << "-1"; 
    }
    return 0;
}