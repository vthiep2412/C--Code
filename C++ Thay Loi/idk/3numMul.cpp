#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("bai2.inp", "r", stdin);
    //freopen("bai2.out", "w", stdout);
    ll n,cntneg = 0,neg=0,pos=0;
    cin>>n;
    vector<ll> a(n);
    for(ll i=0; i<n; i++){
        cin>>a[i];
        // if(a[i]<0) cntneg++;
    }
    sort(all(a));
    neg = a[0]*a[1]*a.back();
    pos = a[n-1]*a[n-2]*a[n-3];
    cout<<max(neg,pos);
    return 0;
}