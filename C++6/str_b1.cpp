#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // hmm this is wrong the file name not as same as the file are coding.
    // freopen("str_b2.inp", "r", stdin);
    // freopen("str_b2.out", "w", stdout);
    string s;
    getline(cin, s);
    int cnt = 0;
    string str;
    cin>>str;
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i = 0; i <= s.size(); i++){
        if(s.substr(i, str.size()) == str) cnt++;
    }
    cout << cnt;
}