#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define all(a) a.begin(), a.end()
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MONEY.INP", "r", stdin);
    freopen("MONEY.OUT", "w", stdout);

    ll g, s, k, n;
    cin >> g >> s >> k >> n;

    while(n--) {
        ll p, q, r;
        cin >> p >> q >> r;

        k -= r;
        while (k < 0) {
            s--;
            k += 29;
        }

        s -= q;
        while (s < 0) {
            g--;
            s += 17;
        }

        g -= p;

        if (g < 0) {
            cout << -1 << '\n';
            return 0;
        }
    }

    cout << g << " " << s << " " << k << '\n';

    return 0;
}