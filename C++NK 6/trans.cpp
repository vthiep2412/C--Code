#include <bits/stdc++.h>
using namespace std;

pair<int, int> greedy(int n, int a, int b) {
    int minCost = INT_MAX;
    int ansBus = 0, ansTaxi = 0;
    for (int bus = n / 50; bus >= 0; --bus) {
        int rem = n - bus * 50;
        int taxi = (rem + 3) / 4;
        int cost = bus * a + taxi * b;
        if (cost < minCost) {
            minCost = cost;
            ansBus = bus;
            ansTaxi = taxi;
        }
    }
    return {ansBus, ansTaxi};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TRANS.INP", "r", stdin);
    freopen("TRANS.OUT", "w", stdout);
    int n, a, b;
    cin >> n >> a >> b;

    pair<int, int> ans = greedy(n, a, b);
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}
