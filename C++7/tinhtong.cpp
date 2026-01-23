#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    string n;
    int m;
    cin>>n;
    cin>>m;
    string s;
    s=n.substr(n.size()-m,m);
    int sum=0;
    for(char c:s){
        sum+=c-'0';
    }
    cout<<sum;
    return 0;
}