#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("DIENTICH.inp", "r", stdin);
    //freopen("DIENTICH.out", "w", stdout);
    ll r, best=0;
    cin >> r;
    for(ll x = 1; x<=r; x++){
        ll y = (ll)sqrt((double)r*r - (double)x*x);
        best = max(best, 4*x*y);
    }
    cout << best;
    return 0;
}