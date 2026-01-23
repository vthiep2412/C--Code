#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("GUITAR.inp", "r", stdin);
    freopen("GUITAR.out", "w", stdout);

    int n, p;
    cin >> n >> p;

    vector<stack<int>> strings(7);
    ll moves = 0;

    for (int i = 0; i < n; ++i) {
        int s, f;
        cin >> s >> f;

        while (!strings[s].empty() && strings[s].top() > f) {
            strings[s].pop();
            moves++;
        }

        if (strings[s].empty() || strings[s].top() < f) {
            strings[s].push(f);
            moves++;
        }
    }

    cout << moves << endl;

    return 0;
}