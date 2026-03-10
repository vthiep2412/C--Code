#include <bits/stdc++.h>
using namespace std;

const int maxN = 10000005;
int sD[maxN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("IMPERFECT.INP", "r", stdin);
    freopen("IMPERFECT.OUT", "w", stdout);

    for (int i = 1; i <= maxN / 2; ++i) {
        for (int j = 2 * i; j < maxN; j += i) {
            sD[j] += i;
        }
    }

    int a, b;
    cin >> a >> b;

    long long ans = 0;
    for (int i = a; i <= b; ++i) {
        long long diff = i - sD[i];
        if (diff < 0) ans -= diff;
        else ans += diff;
    }

    cout << ans << "\n";

    return 0;
}