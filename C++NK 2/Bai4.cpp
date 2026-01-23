#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    long long s = 1, a = 1, b = 1, i = 3;
    while (i <= n) {
        s = a + b;
        a = b;
        b = s;
        i++;
    }
    return s;
}

int main() {
    long long n;
    cin >> n;
    long long ketqua = solve(n);
    cout << ketqua;
    return 0;
}