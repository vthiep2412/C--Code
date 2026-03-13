#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("tinhtoan.inp","r",stdin);
    // freopen("tinhtoan.out","w",stdout);
    ll n;
    cin>>n;
    vector<int> a(n);
    stack<pair<int,int>> q;
    for(int &x:a) cin>>x;
    int curmoney=0, cnt=0;
    bool isMoney=0;
    for(int i=0;i<n;i++){
        if(a[i] > 0) {
            curmoney+=a[i];
            isMoney=true;
            cnt++;
        }
        if(a[i] < 0){
            cnt++;
            if(isMoney) {
                q.push({a[i], i});
                isMoney=false;
            } else q.back() = {a[i]+q.back().first, q.back().second};
        }
        while(!q.empty() and curmoney > abs(q.back().first)) {
            curmoney -= abs(q.back().first);
            cnt += (i-q.back().second)*2;
            q.pop();
        }
    }
    cout<<cnt;
    return 0;
}