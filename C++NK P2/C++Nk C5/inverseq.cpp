#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("inverseq.INP", "r", stdin);
    freopen("inverseq.OUT", "w", stdout);
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long x = n - 1;
        int ones = __builtin_popcountll(x);
        cout << (ones & 1) << "\n";
    }
    return 0;
}
