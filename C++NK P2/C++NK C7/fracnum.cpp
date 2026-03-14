#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FRACNUM.INP", "r", stdin);
    freopen("FRACNUM.OUT", "w", stdout);
    ll n;
    cin >> n;
    ll a = ceil((sqrtl(1.0L + 8.0L * n) - 1.0L) / 2.0L);
    while (a*(a-1)/2 >= n) a--;
    while (a*(a+1)/2 < n) a++;

    ll b = a * (a - 1) / 2;
    ll p = n - b;
    ll p1, p2;
    if (a % 2 == 0) {
        p1 = p;
        p2 = a - p + 1;
    } else {
        p1 = a - p + 1;
        p2 = p;
    }
    cout << p1 <<"/"<< p2;
}