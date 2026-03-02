#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXK = 5000;
int ans[MAXK + 1];
vector<int> primes;
int minPrime[MAXK + 1];

void linearSieve() {
    for (int i = 2; i <= MAXK; ++i) {
        if (minPrime[i] == 0) {
            minPrime[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > minPrime[i] || (ll)i * p > MAXK) break;
            minPrime[i * p] = p;
        }
    }
}

void precompute() {
    linearSieve();
    int sz = primes.size();
    for (int i = 0; i < sz; ++i) {
        int x = primes[i];
        if (3 * x > MAXK) break;
        for (int j = i; j < sz; ++j) {
            int y = primes[j];
            if (x + 2 * y > MAXK) break;
            for (int k = j; k < sz; ++k) {
                int z = primes[k];
                int sum = x + y + z;
                if (sum > MAXK) break;
                ans[sum]++;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("EQUATION.INP", "r")) {
        freopen("EQUATION.INP", "r", stdin);
        freopen("EQUATION.OUT", "w", stdout);
    }

    precompute();

    int k;
    while (cin >> k) {
        if (k > MAXK) cout << 0 << "\n";
        else cout << ans[k] << "\n";
    }

    return 0;
}