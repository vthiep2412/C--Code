#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
int main() {
    freopen("IDOLS.INP", "r", stdin);
    freopen("IDOLS.OUT", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    unordered_map<int, int> cnt;
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int id;
            cin >> id;
            cnt[id]++;
            if (cnt[id] > max_val) max_val = cnt[id];
        }
    }
    vector<int> res;
    for (auto p : cnt) {
        if (p.second == max_val) res.push_back(p.first);
    }
    sort(res.begin(), res.end());
    for (int x : res) cout << x << " ";
    return 0;
}