#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("NTFS.inp", "r", stdin);
    freopen("NTFS.out", "w", stdout);
    long long n;
    cin >> n;
    long long b;
    b = (n / 4096);
    b*=4;
    if (n % 4096 != 0) {
        b += 4;
    }
    cout << b;
}
