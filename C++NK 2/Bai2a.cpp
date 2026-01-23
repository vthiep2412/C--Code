#include <bits/stdc++.h>
using namespace std;

double solve(int n, double x) {
    double s = 0,j = 1,t = 1;
    int i = 1;
    while (i <= n) {
        j = j * i;
        t = t * x;
        if (i % 2 == 0) {
            s = s - t / j;
        } else {
            s = s + t / j;
        }
        i++;
    }
    return s;
}

int main() {
    int n;
    double x;
    cin >> n >> x;
    double ketqua = solve(n, x);
    cout << ketqua;
    return 0;
}
