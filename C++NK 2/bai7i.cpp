#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
    int i = 2;
    int c = sqrt(n);
    if (n < 2) {
        return false;
    }
    while (i <= c) {
        if (n % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool ketqua = solve(n);
    (ketqua == true) ? cout << "Yes prime" : cout << "No prime";
    return 0;
}

