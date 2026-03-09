#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

ll solve(ll target, ll a, ll b) {
    if (a < b) swap(a, b); 
    for (ll i = 0; i <= min(target / a, b); ++i) {
        ll rem = target - i * a;
        if (rem >= 0 && rem % b == 0) {
            ll j = rem / b;
            return i + j;
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("robot.inp", "r", stdin);
    //freopen("robot.out", "w", stdout);
    ll n, a, b, c, d;
    cin >> n;
    cin >> a >> b >> c >> d;
    ll tar1 = solve(n-1, a, b);
    if(tar1 == -1) {
        cout << tar1;
        return 0;
    }
    ll tar2 = solve(n-1, c, d);
    if(tar2 == -1) {
        cout << tar2;
        return 0;
    }
    cout<<tar1+tar2;
    return 0;
}

