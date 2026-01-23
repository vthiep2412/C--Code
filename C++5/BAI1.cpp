#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BAI1.inp","r",stdin);
    freopen("BAI1.out","w",stdout);
    int m,n,k;
    cin>>m>>n>>k;
    cout<<__gcd(__gcd(m,n),k)<<endl;
    return 0;
}
