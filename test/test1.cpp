#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()


vector<bool> isPrime(1e6 + 5, true);
void sieve(int n) {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    ll n = 1e6;
    sieve(n);
    vector<int> prefix;
    prefix.push_back(0);
    for(int i = 1; i <= n; i++) {
        prefix.push_back(prefix.back() + isPrime[i]);
    }
    cout<<prefix[n] - prefix[1];
    return 0;
}