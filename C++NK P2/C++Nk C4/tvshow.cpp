#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("tvshow.inp", "r", stdin);
    freopen("tvshow.out", "w", stdout);
    int n;
    cin >> n;
    int cnt = 0, cntRes = 0, x, y;
    vector<pair<int, int>> a;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (auto [x, y] : a) {
        while (!pq.empty() && x >= pq.top()) {
            cnt--;
            pq.pop();
        }
        cntRes += cnt;
        cnt++;
        pq.push(y);
    }
    cout << cntRes;
    return 0;
}
