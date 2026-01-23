#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    string s,str;
    cin >> s >> str;
    int cnt = 0;
    for(int i = 0; i < s.size(); i++){
        for(int j = i+1; j < str.size(); j++){
            if(s[i] == str[j]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}