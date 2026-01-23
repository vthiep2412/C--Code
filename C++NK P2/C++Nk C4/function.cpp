#include <iostream>
using namespace std;
#define ll long long
ll solve(ll n) {
    ll result = 1;
    for (ll i = 2; i <= n; ++i) {
        result = (result * i) % 9;
    }
    return result == 0 ? 9 : result;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("function.inp", "r", stdin);
    freopen("function.out", "w", stdout);
    ll n;
    cin >> n;
    cout << solve(n);
    return 0;
}
