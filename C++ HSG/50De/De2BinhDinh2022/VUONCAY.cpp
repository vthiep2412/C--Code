#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("VUONCAY.inp", "r", stdin);
    //freopen("VUONCAY.out", "w", stdout);
    int n,m;
    ll ans=0;
    cin>>n>>m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>a[i][j];

    ans += (n+m)*2;

    for(int i = 0; i < n-1; i++)
        for(int j = 0; j < m; j++)
            ans+= (a[i][j] != a[i+1][j]);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m-1; j++)
            ans+= (a[i][j] != a[i][j+1]);
    cout << ans;
    return 0;
}