#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

vector<bool> isPrime;
vector<long long> prefixProduct;

void sieve(int n) {
    isPrime.assign(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void buildPrefixProduct(int n) {
    prefixProduct.resize(n + 1);
    prefixProduct[0] = 1;
    for (int i = 1; i <= n; i++) {
        prefixProduct[i] = prefixProduct[i - 1];
        if (isPrime[i]) { // direct O(1) prime check
            prefixProduct[i] = (prefixProduct[i] * i) % MOD;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    vector<int> queries(T);
    int maxN = 0;
    for (int i = 0; i < T; i++) {
        cin >> queries[i];
        maxN = max(maxN, queries[i]);
    }

    sieve(maxN);
    buildPrefixProduct(maxN);

    for (int n : queries) {
        cout << prefixProduct[n] << "\n";
    }

    return 0;
}
