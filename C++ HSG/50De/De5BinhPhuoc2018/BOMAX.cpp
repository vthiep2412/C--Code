#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    ll n, maxS=0, p1=-1, p2=-1;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n-2;i++){
        ll sum = a[i]+a[i+1]+a[i+2];
        if(sum > maxS){
            maxS = sum;
            p1 = i;
            p2 = i+2;
        }
    }
    cout<<maxS<<"\n"<<p1+1<<" "<<p2+1;
    return 0;
}