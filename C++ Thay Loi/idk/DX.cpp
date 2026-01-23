#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("DX.inp", "r", stdin);
    freopen("DX.out", "w", stdout);
    string s,t;
    cin>>s;
    int l=0,r=s.size()-1;
    while(l<r)
    {
        if(s[l]!=s[r])
        {
            cout<<"NO";
            return 0;
        }
        l++;
        r--;
    }
    cout<<"YES";
    return 0;
}