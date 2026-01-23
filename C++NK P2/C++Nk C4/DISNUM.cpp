#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define st first
#define nd second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 freopen("DISNUM.inp", "r", stdin);
 freopen("DISNUM.out", "w", stdout);
    umap<ll,ll> map;
    ll n,nhap;
    cin>>n;
    for(ll i = 0;i<n;i++){
        cin>>nhap;
        map[nhap]++;
    }
    cout<<map.size();
    return 0;
}