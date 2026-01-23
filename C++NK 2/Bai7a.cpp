#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int cnt = 0;
    while (n > 0) {
        n = n / 10;
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}
