#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    string s;
    int cnt=0;
    cin>>s;
    unordered_set<char> seen;
    for(char c:s){
        if (seen.find(c)!= seen.end()){
            cnt = -1;
            break;
        }
        cnt++;
        seen.insert(c);
    }
    cout<<cnt;
    return 0;
}