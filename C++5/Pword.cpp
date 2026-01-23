#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pword.inp", "r", stdin);
    freopen("pword.out", "w", stdout);
    string s;
    cin >> s;
    int n = s.length();
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(isdigit(s[i])){
            if((s[i]-'0')% 2 == 0){
                sum+= s[i]-'0';                
            } 
        }
    }
    cout << sum;
}