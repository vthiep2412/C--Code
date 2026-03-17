#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll solve(ll n) {
    ll s=0;
    if(n%3==0) {
        s+=(n/3)*7;
        return s;
    } if(n%3==1) {
        s+=(n/3-1)*7;
        s+=4;
        return s; 
    } if(n%3==2) {
        s+=(n/3)*7;
        s+=1;
        return s; 
    }
    return s;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ledlight.inp", "r", stdin);
    freopen("ledlight.out", "w", stdout);
    ll n;
    cin>>n;
    cout<<solve(n);
    return 0;
}