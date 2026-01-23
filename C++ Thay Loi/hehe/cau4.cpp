#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CAU4.INP","r",stdin);
    freopen("CAU4.OUT","w",stdout);

    int T;
    if (!(cin >> T)) return 0;
    vector<pair<int,int>> qs(T);
    int maxB = 0;
    for (int i = 0; i < T; ++i) {
        int a,b; cin >> a >> b;
        qs[i] = {a,b};
        if (b > maxB) maxB = b;
    }
    int N = maxB;
    vector<int> primes;
    vector<char> isComp(N+1, 0);
    for (int i = 2; i <= N; ++i) {
        if (!isComp[i]) {
            primes.push_back(i);
            if ((ll)i * i <= N) {
                for (int j = i*i; j <= N; j += i) isComp[j] = 1;
            }
        }
    }
    for (auto &q : qs) {
        int a = q.first, b = q.second;
        ll ans = 1;
        for (int p : primes) {
            if (p > b) break;
            ll pPow = p;
            ll E = 0;
            while (pPow <= b) {
                ll cnt = b / pPow - ( (a-1) / pPow );
                if (cnt) E += cnt;
                if (pPow > (ll)b / p) break;
                pPow *= p;
            }
            if (E > 0) {
                ans = ans * ((2*E + 1) % MOD) % MOD;
            }
        }
        cout << ans % MOD << "\n";
    }
    return 0;
}
