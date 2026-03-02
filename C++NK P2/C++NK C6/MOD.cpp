#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    if (fopen("MOD.INP", "r")) {
        freopen("MOD.INP", "r", stdin);
        freopen("MOD.OUT", "w", stdout);
    }

    long long a, c, L, R;
	cin >> a >> c >> L >> R;

    long long ans = 0;

    if (a < c) ans = 0;
    else if (a == c) {
        long long start_b = max(L, a + 1);
        if (start_b <= R) ans = R - start_b + 1;
		else ans = 0;
    } 
    else {
        long long N = a - c;
        long long min_b = max(L, c + 1);
        long long max_b = R;

        for (long long i = 1; i * i <= N; ++i) {
            if (N % i == 0) {
                long long divisor1 = i;
                long long divisor2 = N / i;

                if (divisor1 >= min_b && divisor1 <= max_b) {
                    ans++;
                }
                if (divisor1 != divisor2 && divisor2 >= min_b && divisor2 <= max_b) {
                    ans++;
                }
            }
        }
    }

    cout << ans << "\n";

    return 0;
}