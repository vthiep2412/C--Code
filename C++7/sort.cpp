#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("SORT.INP", "r", stdin);
    // freopen("SORT.OUT", "w", stdout);
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a;
    for (int r = 0; r < m; r++) {
        for (int i = 1; i <= n; i++) {
            if (i % m == r) {
                a.push_back(i);
            }
        }
    }
    cout << a[t-1];
    return 0;
}


