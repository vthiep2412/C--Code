#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define unordered_set uset
#define unordered_map umap

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("beehive.inp", "r", stdin);
    freopen("beehive.out", "w", stdout);
    ll n;
    cin >> n;
    cout<<3*(n*n) - 3*n + 1;
    return 0;
}