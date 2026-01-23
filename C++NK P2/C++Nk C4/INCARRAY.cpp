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
    freopen("INCARRAY.inp", "r", stdin);
    freopen("INCARRAY.out", "w", stdout);
    ll n,cnt=0;
    cin>>n;
    vc<ll> a(n);
    for(ll i = 0;i<n;i++) cin>>a[i];
    for(ll i = 0;i<n-1;i++){
        if(a[i] > a[i+1]) {
            cnt += a[i] - a[i+1];
            a[i+1] = a[i];
        }
    }
    cout<<cnt;
    return 0;
}