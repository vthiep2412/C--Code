#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
    int ht = 0, trc = INT_MAX;
    while (n > 0) {
        ht = n % 10;
        if (ht > trc) {
            return false;
        } else {
            trc = ht;
            n = n / 10;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool ketqua = solve(n);
    (ketqua) ? cout << "Yes" : cout << "No";
    return 0;
}