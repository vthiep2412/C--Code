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
#define str string

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("OLYMPIC.inp", "r", stdin);
    freopen("OLYMPIC.out", "w", stdout);
    map<ll,vc<ll>> Pmap;
    ll n, point;
    cin>> n>> point;
    ll cntPoint=0;
    for(ll i=0;i<n;i++){
        ll p1,exp;
        cin>>p1>>exp;
        if(point>=p1){
            cntPoint++;
            point+=exp;
        } else {
            if(Pmap[p1].size()==0){
                Pmap[p1].pb(0);
                Pmap[p1].pb(exp);
                Pmap[p1][0] += exp;
            } else {
                Pmap[p1].pb(exp);
                Pmap[p1][0] += exp;
            }
        }
    }
    for(auto it:Pmap){
        if(point>=it.st){   
            cntPoint+=it.nd.size()-1;
            point+=it.nd[0];
        }
    }
    cout<< cntPoint;
    return 0;
}
