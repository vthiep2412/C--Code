#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("TNV3.inp", "r", stdin);
    // freopen("TNV3.out", "w", stdout);
    int n;
    cin>>n;
    map<int,int> mp;
    pair<int,int> pr{0,INT_MIN};
    for(int i=1;i<=n;i++){
        int nhap;
        cin>>nhap;
        mp[nhap]++;
    }
    for(auto i:mp){
        cout<<i.first<<" "<<i.second<<"\n";
    }
    cout<<"\n";
    for(map<int,int>::reverse_iterator i = mp.rbegin(); i!= mp.rend();i++){
        pair<int,int> x = *i;
        if(x.second > pr.second){
            pr = {x.first,x.second};
        }
    }
    cout<<pr.first<<" "<<pr.second;
    return 0;
}