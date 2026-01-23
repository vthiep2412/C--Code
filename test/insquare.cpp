#include <bits/stdc++.h>
using namespace std;

bool ktscp(int n){
    int x = sqrt(n);
    return (x * x) == n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("insquare.inp", "r", stdin);
    // freopen("insquare.out", "w", stdout);
    int a,b,cnt = 0;
    cin >> a >> b;
    for(int i = a; i <= b; i++){
        if(ktscp(i)) cnt++;
    }
    cout << cnt;
    return 0;   
}
// cout  <<
// cin >>
// c++ c input => cin