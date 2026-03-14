#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool solve(){
    double n,m;
    cin>>n>>m;
    return ((n*3.0+m)/4.0 >= 5.0);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("diemtb.inp","r",stdin);
    freopen("diemtb.out","w",stdout);
    cout<<solve();
    return 0;
}