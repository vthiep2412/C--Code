#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("jfs.inp", "r", stdin);
    // freopen("jfs.out", "w", stdout);
    ll x;
    bool check=false;
    vector<int> a;
    while(cin>>x){
        a.pb(x);
    }
    for(ll i=0;i<a.size();i++){
        for(ll j=i;j<a.size();j++){
            if(a[j]>a[i]){
                cout<<j+1<<" ";
                check=true;
                break;
            }
        }
        if(check==false){
            cout<<-1<<" ";
        }else{
            check=false;
        }
    }
    return 0;
}