#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second

pair<ll,int> maxb, secondb, maxc, secondc;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("CINEMA.inp", "r", stdin);
    freopen("CINEMA.out", "w", stdout);

    ll n;
    cin >> n;

    ll total_base = 0;
    maxb = secondb = {LLONG_MIN, -1};
    maxc = secondc = {LLONG_MIN, -1};

    vector<ll> a(n), b(n), c(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        total_base += a[i];

        ll gainB = b[i] - a[i];
        if (gainB > maxb.fi) {
            secondb = maxb;
            maxb = {gainB, i};
        } else if (gainB > secondb.fi) {
            secondb = {gainB, i};
        }

        ll gainC = c[i] - a[i];
        if (gainC > maxc.fi) {
            secondc = maxc;
            maxc = {gainC, i};
        } else if (gainC > secondc.fi) {
            secondc = {gainC, i};
        }
    }

    ll best_sum;
    int filmB, filmC;

    if (maxb.se != maxc.se) {
        best_sum = total_base + maxb.fi + maxc.fi;
        filmB = maxb.se + 1;
        filmC = maxc.se + 1;
    } else {
        ll opt1 = total_base + maxb.fi + secondc.fi;
        ll opt2 = total_base + secondb.fi + maxc.fi;

        if (opt1 > opt2 || (opt1 == opt2 && 
            make_pair(maxb.se, secondc.se) < make_pair(secondb.se, maxc.se))) {
            best_sum = opt1;
            filmB = maxb.se + 1;
            filmC = secondc.se + 1;
        } else {
            best_sum = opt2;
            filmB = secondb.se + 1;
            filmC = maxc.se + 1;
        }
    }

    cout << best_sum << "\n";
    cout << filmB << " " << filmC << "\n";

    return 0;
}
