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
    freopen("numquiz.inp", "r", stdin);
    freopen("numquiz.out", "w", stdout);
    ll n;
    cin>>n;
    ll x;
    ll gcd = 0;
    for(ll i = 1; i <= n; i++){
        cin>>x;
        if(i==1){
            gcd = x;
        }
        else {
            gcd = __gcd(gcd, x);
        }
    }
    cout<<gcd*n;
    return 0;
}