#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("B_LINES.INP", "r", stdin);
    freopen("B_LINES.OUT", "w", stdout);
    int n,m, k;
    cin >> n >>m>> k;

    map<long long, long long> freq;
    for (int i = 0; i < n*m; ++i) {
        long long x; cin >> x;
        ++freq[x];
    }

    vector<pair<long long, long long>> items(freq.begin(), freq.end());
    sort(items.begin(), items.end(),
        [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first > b.first;
        });

    long long ans = 0;
    int take = min<long long>(k, items.size());
    for (int i = 0; i < take; ++i) ans += items[i].second;

    cout << ans << '\n';
    return 0;
}
