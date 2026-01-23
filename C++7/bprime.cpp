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

int dao(int n){
    int dao = 0;
    while (n > dao) {
        dao = dao * 10 + n % 10;
        n /= 10;
    }
    return dao;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n,cnt=0;
    cin>>n;
    unordered_set<int> seen;
    for(int i = 1; i <=n; i++){
        int nhap;
        cin>>nhap;
        if (seen.find(nhap) != seen.end()) continue;
        if (kt(nhap)&&kt(dao(nhap))) cnt++;
        seen.insert(nhap);
    }
    cout<<cnt;
    return 0;
}
