#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PROMOTION.INP", "r", stdin);
    freopen("PROMOTION.OUT", "w", stdout);
    long n, k;
    cin >> n >> k;

    long a=0,b=n;
    while (b>=k) {
        long new1 = b / k;
        a += new1;
        b = ( b % k ) + new1;
    }

    cout << a << endl;

    return 0;
}