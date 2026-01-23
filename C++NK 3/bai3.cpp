#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
    if (b == 2 * a) {
        return 0;
    } else if (b > 2 * a) {
        return -(b - 2 * a);
    } else {
        return 2 * a - b;
    }
}

int main() {
    int a, b;
    cin >> a >> b;

    int result = solve(a, b);

    if (result == 0) {
        cout << "dang gap doi tuoi";
    } else if (result < 0) {
        cout << "cach day " << abs(result) << " nam";
    } else {
        cout << "sau " << result << " nam nua";
    }

    return 0;
}
