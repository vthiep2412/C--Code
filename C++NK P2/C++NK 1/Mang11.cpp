#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

ll kt(const vector<ll>& v) {
    ll n = v.size();
    if (n <= 1) return n;
    
    for (int i = 0; i < n/2; i++) {
        if (v[i] != v[n-1-i]) {
            return -1;
        }
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mang11.inp", "r", stdin);
    freopen("mang11.out", "w", stdout);
    ll n;
    cin>>n;
    vc<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll mcnt=INT_MIN;
    for(ll i=0;i<n;i++){
        for(ll j=n-1;j>=i;j--){
            if(a[i]==a[j]){
                vector<ll> sub(a.begin() + i, a.begin() + j + 1);
                ll cnt = kt(sub);
                if(cnt>mcnt) mcnt=cnt;
            }
        }
    }
    cout<<mcnt;
    return 0;
}