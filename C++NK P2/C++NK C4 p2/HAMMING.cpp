#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

static vector<ll> gen(ll lim){
    vector<ll> a{1};
    size_t i2=0,i3=0,i5=0;
    for(;;){
        ll n2=a[i2]*2, n3=a[i3]*3, n5=a[i5]*5;
        ll n=min({n2,n3,n5});
        if(n>lim) break;
        if(n!=a.back()) a.push_back(n);
        if(n==n2) ++i2; if(n==n3) ++i3; if(n==n5) ++i5;
    }
    return a;
}

int main(){
    freopen("HAMMING.INP","r",stdin);
    freopen("HAMMING.OUT","w",stdout);
    int t; if(!(cin>>t)) return 0;
    vector<ll> q(t); ll mx=0;
    for(int i=0;i<t;++i){ cin>>q[i]; if(q[i]>mx) mx=q[i]; }
    auto a=gen(mx);
    for(ll x:q){
        ll l=0, r=(ll)a.size()-1, pos=-1;
        while(l<=r){
            ll m=l+(r-l)/2;
            if(a[m]==x){ pos=m; break; }
            if(a[m]<x) l=m+1; else r=m-1;
        }
        if(pos!=-1) cout<<(pos+1)<<'\n';
        else cout<<"Not in sequence\n";
    }
    return 0;
}
