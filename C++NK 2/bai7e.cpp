#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int s = 0, max = -1;
    while (n > 0) {
        s = n % 10;
        n = n / 10;
        if (s % 2 == 0) {
            if (s > max) {
                max = s;
            }
        }
    }
    return max;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}