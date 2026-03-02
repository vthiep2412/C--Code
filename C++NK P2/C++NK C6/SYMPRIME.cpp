#include <bits/stdc++.h>
using namespace std;


const int LIMIT = 20000005;
bool isP[LIMIT], isSym[LIMIT];
vector<int> p;

void sieve(int maxN) {
    int sLimit = min(LIMIT - 1, maxN + 1000); 
    for (int i = 2; i <= sLimit; i++) isP[i] = true;
    for (long long i = 2; i <= sLimit; i++) {
        if (isP[i]) {
            p.push_back(i);
            for (long long j = i * i; j <= sLimit; j += i) isP[j] = false;
        }
    }
    for (int i = 1; i < (int)p.size() - 1; i++) {
        if (p[i+1] == 2 * p[i] - p[i-1]) isSym[p[i]] = true;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SYMPRIME.INP", "r", stdin);
    freopen("SYMPRIME.OUT", "w", stdout);

    int t; cin >> t;
    vector<int> q(t);
    int mx = 0;
    for (int i = 0; i < t; i++) {
        cin >> q[i];
        if (q[i] > mx) mx = q[i];
    }

    sieve(mx);

    for (int n : q) {
        if (isSym[n]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}