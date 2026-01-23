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
    freopen("busroute.inp", "r", stdin);
    freopen("busroute.out", "w", stdout);
    ll a,b,n;
    cin>>a>>b>>n;
    ll curANS = INT_MAX;
    for(int i=0;i<n;i++){
        ll c, m;
        cin>>c>>m;
        vector<ll> v(m);
        for(int j=0;j<m;j++){
            cin>>v[j];
        }
        for(int j=0;j<m;j++){
            if(v[j]==a){
                for(int k=j+1;k<m;k++){
                    if(v[k]==b){
                        curANS = min(curANS, c);
                        break;
                    } 
                }
            } 
        }
    }
    if(curANS == INT_MAX){
        cout<<-1;
        return 0; 
    }
    cout<<curANS;
    return 0;
}