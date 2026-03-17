#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp","r",stdin);
    // freopen(".out","w",stdout);
    string n;
    int m, sum=0;
    cin>>n>>m;
    for(int i=n.size()-1;i >= n.size()-m;i++){
        sum += (n[i]-'0');
    }
    cout<<sum;
    return 0;
}