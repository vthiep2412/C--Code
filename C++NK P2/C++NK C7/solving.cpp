#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p(ll base, ll exp) {
    ll res = 1;
    for (int i = 0; i < exp; i++) res *= base;
    return res;
}

ll sumDig(ll x) {
    ll res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SOLVING.INP", "r", stdin);
    freopen("SOLVING.OUT", "w", stdout);

    ll a, b, c;
    
    cin >> a >> b >> c;

    vector<ll> ans;

    for (ll i = 1; i <= 81; i++) {
        ll x = p(i, a) * b + c;
        if (x > 0 and x <= 1000000000LL 
            and sumDig(x) == i) ans.push_back(x);
    }

    sort(ans.begin(), ans.end());

    if (ans.empty()) cout << "No solution\n";
    else {
        for (ll x : ans) cout << x << "\n";
    }

    return 0;
}