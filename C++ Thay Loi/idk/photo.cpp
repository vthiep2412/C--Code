#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("photo.inp", "r", stdin);
    freopen("photo.out", "w", stdout);
    long long n,s=0;
    cin>>n;
    if(n/2<=100) s = n/2*300;
    else s=n/2*280;
    if(n%2!=0) s=s+250;
    cout<<s;
    return 0;
}