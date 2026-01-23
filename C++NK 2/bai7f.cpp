#include <bits/stdc++.h>
using namespace std;

bool solve(int n) {
    int s = 0, dao = 0, a = n;
    while (n > 0) {
        s = n % 10;
        dao = dao * 10 + s;
        n = n / 10;
    }
    if (dao == a) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    bool ketqua = solve(n);
    (ketqua == true) ? cout << "Yes" : cout << "No";
    return 0;
}
