#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("oioi.inp", "r", stdin);
    freopen("oioi.out", "w", stdout);
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cout << i << "\n";
    }
    cerr<<"Time: "<<1000.*clock()/CLOCKS_PER_SEC<<" ms\n";
    return 0;
}