#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();
    freopen("numpos.inp", "r", stdin);
    freopen("numpos.out", "w", stdout); 
    string s;
    long long k;
    cin >> k;
    if(k == 1||k == 2||k == 3){
        cout<<k;
    }
    cout<<(k-2)*3;
}