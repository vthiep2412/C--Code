#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("GCD.INP", "r", stdin );
    freopen("GCD.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<ll> a(n+2), pref(n+2), suff(n+2);
    for (int i = 1; i <= n; i++)cin >> a[i];
    pref[0] = 0;
    for (int i = 1; i <= n; i++)pref[i] = __gcd(pref[i-1], a[i]);
    suff[n+1] = 0;
    for (int i = n; i >= 1; i--)suff[i] = __gcd(suff[i+1], a[i]);
    ll bestGCD = 0;
    int bestPos = 1;

    for (int i = 1; i <= n; i++) {
        ll gcdWithout = __gcd(pref[i-1], suff[i+1]);
        if (gcdWithout > bestGCD) {
            bestGCD = gcdWithout;
            bestPos = i;
        }
    }

    cout << bestPos << " " << bestGCD;
    return 0;
}
