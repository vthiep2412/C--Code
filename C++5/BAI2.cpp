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

vector<long long> ungto(long long n){
    vector<long long> kq;
    const long long c2 = sqrt(n);
    for (long long i = 1; i <= c2; ++i) {
        if (n % i == 0) {
            if (kt(i)) kq.push_back(i);
            if (i != n / i && kt(n / i)) kq.push_back(n / i);
        }
    }
    sort(kq.begin(), kq.end());
    return kq;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BAI2.inp", "r", stdin);
    freopen("BAI2.out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> kq = ungto(n);
    for (long long i : kq) {
        cout << i << " ";
    }
    return 0;
}
