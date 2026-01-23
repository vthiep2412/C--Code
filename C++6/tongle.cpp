#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("tongle.inp", "r", stdin);
    // freopen("tongle.out", "w", stdout);
    int n,sum=0,j=1;
    cin >> n;
    for(int i = 1; i <= n+1; i++){
        sum+=j;
        j+=2;
    }
    cout << sum;

}