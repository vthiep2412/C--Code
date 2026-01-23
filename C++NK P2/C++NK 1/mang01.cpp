#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("mang01.inp", "r", stdin);
    freopen("mang01.out", "w", stdout);
    ll n,x;
    cin>>n>>x;
    ll oi,cnt=0;
    for(ll i=0;i<n;i++) {
        cin >> oi;
        if((oi!=0)&&(x%oi==0)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}