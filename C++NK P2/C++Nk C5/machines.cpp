#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

bool canProduce(const vector<ll> &a, ll n, ll k) {
    ll res = 0;
    for (ll haha : a){
        res += k/haha;
        if (res >= n) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("machines.inp", "r", stdin);
    freopen("machines.out", "w", stdout);
    ll n,k, min = INT_MAX;
    cin>>n>>k;
    vector<ll> a(n);
    for (ll i=0;i<n;i++){
        cin>>a[i];
        min = std::min(a[i],min);
    }
    ll l=0,r=min * k;
    while (r-l>1){
        ll mid=(l+r)/2;
        if (canProduce(a,k,mid)) r=mid;
        else l=mid;
    }
    cout<<r;

    return 0;
}