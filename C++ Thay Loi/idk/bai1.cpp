#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("bai1.inp", "r", stdin);
    freopen("bai1.out", "w", stdout);
    int m,n,k;
    cin>>m>>n>>k;
    cout<<__gcd(m,__gcd(n,k));
    return 0;
}