#include <bits/stdc++.h>
using namespace std;

bool kt(long long n){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    const long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mang06.inp", "r", stdin);
    freopen("mang06.out", "w", stdout);
    int n,mindex=-1,maxi=-1;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int nhap;
        cin >> nhap;
        if (!kt(nhap)) {
            continue;
        }else{
            if (nhap > maxi) {
                maxi = nhap;
                mindex = i; 
            }
        }
    }
    cout << mindex;
    return 0;
}