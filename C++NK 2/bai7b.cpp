#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int s = 0, dao = 0;
    while (n > 0) {
        s = n % 10;
        dao = dao * 10 + s;
        n = n / 10;
    }
    return dao;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}
