#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // the name of freeopen i/o need to be as same as the file are coding that the law in code problem in competition.
    // freopen("tinhtong.inp", "r", stdin);
    // freopen("tinhtong.out", "w", stdout);
    // this code have done
    long long n,cnt=0;
    cin >> n;
    for(long long i = 1; i <= n; i++){
        long long x;
        x=(i*(i+1))/2; 
        if(x>n) break;
        if((n-x)%i==0){
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}