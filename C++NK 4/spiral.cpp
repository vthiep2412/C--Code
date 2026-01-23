#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("spiral.inp", "r", stdin);
    // freopen("spiral.out", "w", stdout);
    long long n;
    cin >> n;
    long long s = (2 * n * n * n + n) / 3;
    cout << s << "\n";
    return 0;
}
