#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("NUMSPIRAL.inp", "r", stdin);
    freopen("NUMSPIRAL.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        ll z = max(n,m);
        ll central = (z*z) - z + 1;
        if(z%2==0)
            cout<<central + (n-m);
        else 
            cout<<central - (n-m);
        cout<<"\n";
    }
    return 0;
}