#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ondinh.inp", "r", stdin);
    freopen("ondinh.out", "w", stdout);
    umap<double,pair<double,double>> map;
    double n,m,a;
    cin>>n>>m;
    double b;
    while(cin>>a>>b){
        map[a].first++;
        map[a].second += b;
    }
    vector<pair<double,double>> v;
    for(auto x:map){
        double f = x.second.second / x.second.first;
        v.pb(f,x.first);
    }
    sort(v.begin(),v.end(),greater<>());
    for(double i=0;i<m;i++){
        cout<<v[i].second<<" ";
    }
    return 0;
}
