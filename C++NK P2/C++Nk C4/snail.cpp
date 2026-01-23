#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("SNAIL.INP", "r", stdin);
    freopen("SNAIL.OUT", "w", stdout);
    ll a,b,v;
    cin>>a>>b>>v;
    ll day=(v-a)/(a-b);
    if((v-a)%(a-b)!=0) day++;
    cout<<day+1;
    return 0;
}   