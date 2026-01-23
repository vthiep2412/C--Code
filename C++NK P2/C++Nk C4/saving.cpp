#include <iostream>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("saving.inp", "r", stdin);
    freopen("saving.out", "w", stdout);

    long double a, b, cnt = 0, r;
    cin >> a >> r >> b;

    while (a + 1e-9 < b) {
        a += (a * r) / 100.0;
        r += 0.5;
        ++cnt;

        if (cnt > 10000) break;
    }
    cout << (ll)cnt;
    return 0;
}
