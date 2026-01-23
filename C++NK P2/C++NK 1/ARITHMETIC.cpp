#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map

ll mod = 1e9+7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ARITHMETIC.inp", "r", stdin);
    freopen("ARITHMETIC.out", "w", stdout);
    ll n;
    cin>>n;
    vc<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool ohyeah = true;
    vc<ll> temp;
    while(a.size()>1){
        if(ohyeah){
            for(int i=0;i<a.size()-1;i++){
                temp.push_back((a[i]+a[i+1])%mod);
            }
            ohyeah = false;
            a = temp;
            temp.clear();
        } else{
            for(int i=0;i<a.size()-1;i++){
                temp.push_back((a[i]*a[i+1])%mod);
            }
            ohyeah = true;
            a = temp;
            temp.clear();
        }
    }
    cout<<a[0]<<"\n";
    return 0;
}