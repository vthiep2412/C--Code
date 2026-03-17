#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("bcells.inp", "r", stdin);
    freopen("bcells.out", "w", stdout);
    long long n,m,r,c;
    cin>>n>>m>>r>>c;
    int kt = ((r + c) % 2 == 0) ? 1 : 0;
    long long tong = (n*m + kt) / 2;
    cout<<tong<<"\n";
    return 0;
}