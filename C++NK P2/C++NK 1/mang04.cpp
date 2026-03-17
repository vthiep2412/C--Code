#include <bits/stdc++.h>
using namespace std;
// cau 4
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mang04.inp", "r", stdin);
    freopen("mang04.out", "w", stdout);
    int n,min1=INT_MAX,min2=INT_MAX;
    cin >> n;
    for(int i=1;i<=n;i++){
        int nhap;
        cin >> nhap;
        if(min1>nhap){
            min2=min1;
            min1=nhap;
        }
        if(min1!=nhap&&min2>nhap){
            min2=nhap;
        }
    }
    if(min2!=INT_MAX){
        cout << min1 << " " << min2; 
    } else {
        cout << min1 << " " << -1; 
    }
    return 0;
}