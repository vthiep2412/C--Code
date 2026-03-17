#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    string s;
    cin>>s;
    sort(s.begin(),s.end(),greater<int>());
    cout<<s;
    return 0;
}