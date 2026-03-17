#include <bits/stdc++.h>
using namespace std;

string maxstr(string n,string m){
    while(n[0]=='0') n.erase(0,1);
    while(m[0]=='0') m.erase(0,1);
    if(n.size()==0) return m;
    if(m.size()==0) return n;
    if(n.size()>m.size()) return n;
    if(n.size()<m.size()) return m;
    if(n>m) return n;
    return m;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    string mk,maxi="0";
    cin>>mk;
    int cnt=0,st=0,sum=0;
    string s;
    for(int i=0;i<=mk.size();i++){
        if(isdigit(mk[i])){
            if(cnt==0){
                st=i;
            }
            cnt++;
        } else {
            if(cnt>0){
                s=mk.substr(st,cnt);
                maxi = maxstr(maxi,s);
                cnt=0;
            }
        }
    }
    cout << maxi;
    return 0;
}