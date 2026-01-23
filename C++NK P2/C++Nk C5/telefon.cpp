#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("telefon.inp", "r", stdin);
    freopen("telefon.out", "w", stdout);
    ll n,d,cnt = 0;
    cin >> n >> d;
    vector<ll> a(n+1);
    for (ll i=1;i<=n;i++) cin >> a[i];
    for (ll i=1;i<=n;i++){
        for (ll j = i;j<=min(n,i+d);j++){
            if (a[j] == 1){
                i = j;
            } else if (j == min(n,i+d) && a[j] == 0){
                cnt++;
                a[j] = 1;
                i = j;
            }
        }
    }
    cout << cnt;

    return 0;
}