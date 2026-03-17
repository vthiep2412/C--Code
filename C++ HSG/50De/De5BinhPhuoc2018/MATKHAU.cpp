#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string getBigger(string s1, string s2) {
    if (s1.length() > s2.length()) return s1;
    if (s2.length() > s1.length()) return s2;
    
    return (s1 > s2) ? s1 : s2;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("MATKHAU.inp","r",stdin);
    // freopen("MATKHAU.out","w",stdout);
    string n, maxS, curS;
    cin>>n;
    if(isdigit(n[0]) and n[0] != '0') curS += n[0];
    maxS = curS;
    for(int i=1;i<n.size();i++){
        if(isdigit(n[i]) and n[i] != '0' 
        and n[i-1] != '0' and isdigit(n[i-1])){
            curS += n[i];
            maxS = getBigger(maxS, curS);
        } else {
            curS = "";
        }
    }
    cout<<maxS;
    return 0;
}