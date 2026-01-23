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
    // freopen("HAMMING.INP","r",stdin);
    // freopen("HAMMING.OUT","w",stdout);
    int t;
    cin>>t;
    auto a=gen(t);
    cout<<a[t-1];
    return 0;
}

