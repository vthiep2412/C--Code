#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

bool prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}


int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("bai2.inp", "r", stdin);
    freopen("bai2.out", "w", stdout);
    long long n;
    cin >> n;
    map<int,int> m;
    for(long long i=1;i<=sqrt(n);i++) {
        if(n%i==0) {
            if(prime(i)) {
                m[i]++;
            } if(prime(n/i)) {
                m[n/i]++;
            }
        }
    }
    for(auto p:m) {
        for(int i=0;i<p.second;i++) {
            cout<<p.first<<" ";
        }
    }
    return 0;
}