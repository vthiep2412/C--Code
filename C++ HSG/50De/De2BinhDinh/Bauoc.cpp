#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1000005;
bool isPrime[MAX];

void sieve(int m) {
    fill(isPrime, isPrime + m + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int p = 2; p * p <= m; p++)
        if (isPrime[p])
            for (int i = p * p; i <= m; i += p)
                isPrime[i] = false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("BAUOC.INP", "r", stdin);
    freopen("BAUOC.OUT", "w", stdout);

    ll n;
    cin >> n;

    int m = sqrt(n);
    sieve(m);

    int cnt = 0;
    for (int p = 2; p <= m; p++) 
        cnt += isPrime[p];

    cout << cnt;
    return 0;
}