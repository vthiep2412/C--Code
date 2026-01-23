#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool check(ll n) {
    ll cnt = 0, sum = 0;
    ll tmp = n;
    while (tmp > 0) {
        sum += tmp % 10;
        tmp /= 10;
        cnt++;
    }
    return (sum % cnt == 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("bnums.inp", "r", stdin);
    freopen("bnums.out", "w", stdout);
    vector<ll> sieveofnothing;
    for(ll i = 1; i<10;++i) sieveofnothing.push_back(i);
    for (ll i = 11; sieveofnothing.size() < 1000000; ++i) {
        if (check(i)) sieveofnothing.push_back(i);
    }
    ll n;
    while (cin >> n) {
        if (n < 1) break;
        cout << sieveofnothing[n - 1] << "\n";
    }
    return 0;
}