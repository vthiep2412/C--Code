#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("led.inp", "r", stdin);
    freopen("led.out", "w", stdout);
    long long n,k;
    cin >> n >> k;
    if(k>7*n || k<2*n){
        printf("NO SOLUTION");
        return 0;
    }
    long long ktemp = k;
    string res = "";
    vector<int> led = {6,2,5,5,4,5,6,3,7,6};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 10; j++){
            if(i==0 && j==0){
                continue;
            }
            if(k-led[j]>=2*(n-i-1) && k-led[j]<=7*(n-i-1)){
                k-=led[j];
                cout << j;
                break;
            }
            if(i==n-1 && k==led[j]){
                cout << j;
                break;
            }
        }
        for(int j = 9; j >= 0; j--){
            if(i==0 && j==0){
                continue;
            }
            if(ktemp-led[j]>=2*(n-i-1) && ktemp-led[j]<=7*(n-i-1)){
                ktemp-=led[j];
                res += to_string(j);
                break;
            }
            if(i==n-1 && ktemp==led[j]){
                res += to_string(j);
                break;
            }
        }
    }
    cout<<"\n"<<res;
    return 0;
}