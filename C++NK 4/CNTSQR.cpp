#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CNTSQR.INP", "r", stdin);
    freopen("CNTSQR.OUT", "w", stdout);

    long long n,m;
    cin >> n >> m;

    if (n < m){
	    swap(m, n);
    }
    long long x = m * (m + 1) * (2 * m + 1) / 6 + (n - m) * m *(m + 1) / 2;
    cout << x;

    return 0;
}
