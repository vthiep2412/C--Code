#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
void popuntil(string &s){
    while (!s.empty() and s.back() != '/'){
        s.pop_back();
    }
    if (!s.empty())s.pop_back();
}

int skipuntil(string &s, int i){
    while (i < s.size() and s[i] != '/'){
        i++;
    }
    return i;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s="";
    cin>>s;
    string ans="";
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (c == '/') {
            if (ans.empty() || ans.back() != '/') {
                ans += '/';
            }
        } else if (i + 1 < s.size() and c == '.' and i!=0) {
            if (s[i + 1] != '/' and s[i - 1] != '/') {
                ans += c;
            }else if (s[i + 1] == '/') {
                // i = skipuntil(s, i + 1) - 1;
                continue;
            }else if (s[i + 1] == '.'){
                ans.pop_back();
                // i = skipuntil(s, i + 1) - 1;
                popuntil(ans);
                // popuntil(ans);
            }
        } else {
            ans += c;
        }
    }
    while(!ans.empty() && ans.back() == '/' or ans.back() == '.'){
        ans.pop_back();
    }
    if(ans[0] != '/' or ans.size() == 0) ans = '/' + ans;
    cout << ans;
    return 0;
}