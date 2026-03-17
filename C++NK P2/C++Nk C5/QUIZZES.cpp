#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(int n, int k) {
    vector<ll> a(n);
    multiset<ll> s;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) {
        s.insert(a[i]);
        ll reach = 0;
        for (ll x : s) {
            if (x <= reach + 1) reach += x;
            else break;
        }
        if (reach >= k) {
            cout << i + 1 << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("QUIZZES.INP", "r", stdin);
    freopen("QUIZZES.OUT", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        solve(n, k);
    }
    return 0;
}
// 7 12
// 1 2 3 4 5 6 7