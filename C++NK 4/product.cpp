#include <iostream>
using namespace std;

int multiofnum(int n) {
    int multi = 1;
    while (n > 0) {
        int a = n % 10;
        if (a == 0) return 0;
        multi *= a;
        n /= 10;
    }
    return multi;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRODUCT.INP", "r", stdin);
    freopen("PRODUCT.OUT", "w", stdout);
    int l, r;
    cin >> l >> r;
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        int a = multiofnum(i);
        if (a != 0 && i % a == 0) cnt++;
    }
    cout << cnt;
    return 0;
}
