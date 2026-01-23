#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("table.inp", "r", stdin);
    freopen("table.out", "w", stdout);
    ll n;
    cin >> n;
    ll a = n/2;
    if(a*a==n) cout << a << " " << a;
    else if(a*a<n) cout << a << " " << a+1;
    else if(a*a>n) cout << a-1 << " " << a;
    else cout << a+1 << " " << a+1;
    return 0;
}