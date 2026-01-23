#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SCHEDULE.INP", "r", stdin);
    freopen("SCHEDULE.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second > y.second;
    });

    ll curTime = 0, totalTime = 0;
    for (auto [setup, runtime] : a) {
        curTime += setup;
        totalTime = max(totalTime, curTime + runtime);
    }

    cout << totalTime << '\n';
    return 0;
}
