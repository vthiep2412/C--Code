#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("Chohang.inp", "r", stdin);
    //freopen("Chohang.out", "w", stdout);
    ll n, a, b, best=0, tmp;
    cin >> n >> a >> b;
    for(ll i = 1; i<=(ll)n/a; i++){
        tmp = i * a + (ll)((n - i * a) / b) * b;
        best = max(best, tmp);
    }
    cout << best;
    return 0;
}