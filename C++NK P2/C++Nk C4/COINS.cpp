#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("COINS.inp", "r", stdin);
    freopen("COINS.out", "w", stdout);
    map<int,int> map;
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]+m>=b[i]){
            m+=a[i];
        } else {
            int diff = b[i]-a[i];
            map[diff]+=a[i];
        }
    }
    for(auto it:map){
        if(m>=it.first){
            m+=it.second;
        }
    }
    cout<<m;
    return 0;
}