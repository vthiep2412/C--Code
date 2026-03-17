#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define unordered_set uset
#define unordered_map umap

void sqlPushback(vc<ll> &a, ll b) {
    if (a.empty() || b != a.back()) {
        a.push_back(b);
    }
}

vector<long long> solve(long long n) {
    vector<long long> ans;
    long long i = 3;
    double a = sqrt(n);
    while (n % 2 == 0) {   
        sqlPushback(ans, 2);
        n = n / 2;
    }
    while (i <= a) {
        if (n % i == 0) {
            sqlPushback(ans, i);
            n = n / i;
        } else {
            i = i + 2;
        }
    }
    if (n > 1) {
        sqlPushback(ans, n);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PRIMEDIV.inp", "r", stdin);
    freopen("PRIMEDIV.out", "w", stdout);
    long long n;
    cin>>n;
    vector<ll> ans = solve(n);
    for(ll x : ans) cout << x << " ";
    return 0;
}