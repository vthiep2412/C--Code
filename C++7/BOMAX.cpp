#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n;
    cin>>n;
    vector<long long> v(n);
    vector<pair<long long, pair<int,int>>> res;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=0;i<n-2;i++){
        int sum = 0;
        sum = sum + v[i]+v[i+1]+v[i+2];
        res.push_back({sum,{i+1,i+3}});
    }
    sort(res.begin(),res.end());
    for(int i=res.size()-1;i>=0;i--){
        if(i==0) {
            cout<<res[i].first<<"\n"<<res[i].second.first<<" "<<res[i].second.second;
            break;
        }
        if(res[i].first != res[i-1].first) {
            cout<<res[i].first<<"\n"<<res[i].second.first<<" "<<res[i].second.second;
            break;
        }
    }
    return 0;
}