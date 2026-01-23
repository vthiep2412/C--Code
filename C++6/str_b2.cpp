#include <bits/stdc++.h>
using namespace std;

int main(){
    //value for i/o optimize with 0 can make code faster a little bit than the normal.
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("str_b2.inp", "r", stdin);
    // freopen("str_b2.out", "w", stdout);
    int n;
    cin >> n;
    cin.ignore();
    vector<string> v(n);
    for(int i = 0; i < n; i++){
        getline(cin, v[i]); 
    }
    for(int i = 0; i < n; i++){
        string s=v[i];
        for(char& c:s){
            if(toupper(c)==c){
                c = tolower(c);
            } else if(tolower(c)==c){
                c = toupper(c); 
            }
        }
        cout << s <<"\n";
    }
}