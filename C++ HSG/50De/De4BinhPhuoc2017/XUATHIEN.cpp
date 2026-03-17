#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    ll n, tmp, maxi=0;
    cin>>n;
    map<int,int> cnt;
    while(n--){
        cin>>tmp;
        cnt[tmp]++;
        maxi = max(maxi,cnt[tmp]);
    }
    for(const pair<int,int> &x:cnt){
        if(x.second == maxi) {
            cout<<x.first<<"\n"<<maxi;
            break;
        }
    }
    return 0;
}