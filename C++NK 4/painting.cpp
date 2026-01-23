    #include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("PAINTING.inp", "r", stdin);
    // freopen("PAINTING.out", "w", stdout);
    
    long long n;
    int cnt = 0;
    cin >> n;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;
            if (i != n / i) {
                cnt++;
            }
        }
    }
    cout << n - cnt << " " << cnt;

    return 0;
}