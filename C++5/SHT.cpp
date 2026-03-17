#include <bits/stdc++.h>
using namespace std;

int tonguoc(int n){
    int tong = 0;
    for(int i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            tong += i;
            if(i != n / i){
                tong += n / i;
            }
        }
    }
    return tong-n;
}

bool kt(int n) {
    int kq = tonguoc(n);
    if(kq == n) return true;
    return false;
    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SHT.inp", "r", stdin);
    freopen("SHT.out", "w", stdout);
    int n,sum=0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int nhap;
        cin>>nhap;
        if(kt(nhap)){
            sum+=nhap;
        } 
    }
    cout<<sum;
    return 0;
}
