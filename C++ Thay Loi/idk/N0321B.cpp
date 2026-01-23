#include <iostream>
#include <cmath>
using namespace std;
#pragma GCC optimize("Ofast")

long long cpow(long long a, long long b){
    long long res = 1;
    while(b){
        if(b&1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("N0321B.inp", "r", stdin);
    freopen("N0321B.out", "w", stdout);
    long long N;
    cin >> N;

    long long temp = N;
    int digits = 0;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    temp = N;
    long long sum = 0;
    while (temp > 0) {
        int digit = temp % 10;
        sum += cpow(digit, digits);
        temp /= 10;
    }
    if (sum == N)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
