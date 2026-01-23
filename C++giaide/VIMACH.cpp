#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("VIMACH.INP", "r", stdin);
    // freopen("VIMACH.OUT", "w", stdout);

    long long n;
    cin >> n;

    const int mod = 12345;
    long long res = 0;

    if (n >= 4) {
        // Calculate nC4 = n*(n-1)*(n-2)*(n-3)/24
        long long a = n;
        long long b = n - 1;
        long long c = n - 2;
        long long d = n - 3;

        // Use __int128 if overflow occurs; here we'll do modular multiplication
        __int128 t = (__int128)a * b % mod;
        t = t * c % mod;
        t = t * d % mod;
        t = t / 24; // since mod is small, safe to divide directly here

        res = t % mod;
    } else {
        res = 0;
    }

    cout << res << "\n";
    return 0;
}
