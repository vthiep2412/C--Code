#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("RSHIFT.INP", "r", stdin);
    freopen("RSHIFT.OUT", "w", stdout);

    long long n, y = 1;
    cin >> n;
    long long ntemp = n;
    // string x = to_string(n);
    // const int y = x.size();
    long long p = 1;
    while (ntemp > 0) {
        y++;
        ntemp /= 10;
        p *= 10;
    }
    p/=10;
    
    long long maxi = n;
    for (long long i = 1; i < y; i++) {
        if (n % 10 == 0) p/=10;
        long long a = n % 10;
        n = (a * p) + (n / 10);
        maxi = max(maxi, n);
    }

    cout << maxi;
    return 0;
}