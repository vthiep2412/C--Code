#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("BALLOONS.INP", "r", stdin);
    // freopen("BALLOONS.OUT", "w", stdout);
    int n;
    cin >> n;
    int t = 0, s = 0, k = 1;
    while (s < n) {
        s += k * (k + 1) / 2;
        t++;
        k++;
    }
    cout << t << "\n";
    return 0;
}