#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("insquare.inp", "r", stdin);
    freopen("insquare.out", "w", stdout);
    int a,b;
    cin >> a>>b;
    int l = sqrt(a);
    int r = sqrt(b);
    if(l*l < a) l++;
    int cnt = 0;
    while(l*l <= b){
        cnt++;
        l++;
    }
    cout << cnt;
}