#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("TOWERS.inp", "r", stdin);
    freopen("TOWERS.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> tower_tops;

    for (int i = 0; i < n; ++i) {
        int block;
        cin >> block;

        auto it = upper_bound(tower_tops.begin(), tower_tops.end(), block);

        if (it == tower_tops.end()) {
            tower_tops.push_back(block);
        } else {
            *it = block;
        }
    }

    cout << tower_tops.size() << endl;

    return 0;
}