#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PRODIG.INP", "r", stdin);
    freopen("PRODIG.OUT", "w", stdout);
    int n;
    cin >> n;
    if (n == 0) {
        cout << 10;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> d;
    for (int i = 9; i >= 2; --i) {
        while (n % i == 0) {
            d.push_back(i);
            n /= i;
        }
    }
    if (n > 1) {
        cout << -1 << "\n";
        return 0;
    }
    sort(d.begin(), d.end());
    for (int x : d) cout << x;
    return 0;
}