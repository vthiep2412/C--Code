#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    string s;
    cin>>s;
    for(char x: s){
        char c = tolower(x);
        if(!strchr("aeiou",c)){
            cout<<"."<<c;
        }
    }
    return 0;
}