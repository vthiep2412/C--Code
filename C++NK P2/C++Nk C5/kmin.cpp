#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("kmin.inp", "r", stdin);
    freopen("kmin.out", "w", stdout);
    int n;
    cin >> n;

    unordered_set<int> s;
    s.reserve(n * 2);
    s.max_load_factor(0.7);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n + 1) s.insert(x);
    }

    for (int k = 1; k <= n + 1; k++) {
        if (s.find(k) == s.end()) {
            cout << k << "\n";
            break;
        }
    }

    return 0;
}
