#include <bits/stdc++.h>
using namespace std;

int main(){
    string s= "";
    string str;
    cin >> str;
    char k;
    cin >> k;
    if (!isdigit(k)) {
        return 0;
    }
    int n = str.size();
    for(int i = 0; i < n; i++){
        if(i + 2 < n && str[i] == k && str[i+2] == k && str[i+1] != k){
            s.push_back(str[i+1]);
        }
    }
    cout << s;
}