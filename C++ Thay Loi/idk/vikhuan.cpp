#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("vikhuan.inp", "r", stdin);
    freopen("vikhuan.out", "w", stdout);
    long long n,a=1;
    cin>>n;
    for(long long i=1;i<=n;i++){
        a=a*2;
    }
    cout<<a;
    return 0;
}