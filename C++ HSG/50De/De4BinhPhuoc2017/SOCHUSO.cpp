#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SOCHUSO.inp","r",stdin);
    freopen("SOCHUSO.out","w",stdout);
    int cnt=0;
    string n;
    cin>>n;
    for(char x:n){
        cnt += isdigit(x);
    }
    for(char x:n){
        if(isdigit(x)) cnt++;
    }
    
    cout<<cnt;
    return 0;
}