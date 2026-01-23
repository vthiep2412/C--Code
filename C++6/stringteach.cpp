#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,x,y;
    getline(cin,s);
    getline(cin,x);
    getline(cin,y);
    for(int i=0;i<s.length();i++){
        string a = s.substr(i,x.length()-1);
        if(a==x){
            s.replace(i,x.length(),y);
            i+=y.length()-1; 
        }
    }
    cout << s;
}