#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

vector<int> build(int n, vector<int> &a) {
    vector<int> oddly;
    oddly.reserve(n);
    oddly.push_back(1);
    vector<int> erm(n+1,0);
    for(int i = 2; i <= n; i++){
        int vitri = a[i];
        oddly.insert(oddly.begin() + vitri, i);
    }
    for(int i = 0;i<n;i++){
        int x = oddly[i];
        erm[x] = i + 1;
    }
    return erm;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("hrank.inp", "r", stdin);
    freopen("hrank.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<int> a(n + 1, 0);
    for(int i = 2; i <= n; i++) cin >> a[i];
    vector<int> rank = build(n, a);
    while(q--) {
        int t; cin >> t;
        cout << rank[t] << "\n";
    }
    return 0;
}