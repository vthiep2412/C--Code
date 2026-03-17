#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("uocle.inp","r",stdin);
    freopen("uocle.out","w",stdout);
    int n,sum=0,cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if ( n % i == 0 && i % 2 != 0){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}