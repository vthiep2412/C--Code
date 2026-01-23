#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tonguoc.inp","r",stdin);
    freopen("tonguoc.out","w",stdout);
    int n,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        if ( n % i == 0){
            sum+=i;
        }
    }
    cout<<sum;
    return 0;
}