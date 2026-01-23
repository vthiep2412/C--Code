#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FREECASH.INP", "r", stdin);
    freopen("FREECASH.OUT", "w", stdout);

    int n;
    cin >> n;
    map<int, int> cnt;

    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        int t = h * 60 + m;
        cnt[t]++;
    }

    int res = 0;
    for (auto &p : cnt) {
        res = max(res, p.second);
    }

    cout << res << "\n";
    return 0;
}
