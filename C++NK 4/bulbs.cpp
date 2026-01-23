#include <iostream>
#include <math.h>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BULBS.INP", "r", stdin);
    freopen("BULBS.OUT", "w", stdout);

    long long n;
    cin >> n;

    const long long c = sqrt(n);

    if(c * c == n) cout << "ON";
    else cout << "OFF";

    return 0;
}
