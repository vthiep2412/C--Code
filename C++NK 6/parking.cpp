#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define unordered_set uset
#define unordered_map umap

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("parking.inp", "r", stdin);
    freopen("parking.out", "w", stdout);
    ll n,m,a,b;
    cin >> n >> m;
    (n%2==0) ? a = n/2: a = (n+1)/2;
    (m%2==0)? b = m/2: b = (m+1)/2;
    cout << a*b;
    return 0;
}