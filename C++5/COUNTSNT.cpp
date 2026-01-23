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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("COUNTSNT.inp", "r", stdin);
    freopen("COUNTSNT.out", "w", stdout);
    int n,cnt=0;
    cin >> n;
    int nhap;
    for (int i = 0; i < n; i++) {
        cin >> nhap;
        if(kt(nhap)){
            cnt++; 
        }
    }
    (cnt > 0)? cout << cnt : cout << "-1";
    return 0;
}
