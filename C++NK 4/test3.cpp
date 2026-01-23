#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

long long binSeaLow(vector<long long> &v, long long x){
    long long l = 0, r = v.size() - 1;
    while (l < r){
        long long m = l + (r - l) / 2;
        if (v[m] < x){
            l = m + 1;
        }
        else r = m;
    }
    return l;

}

long long DP(const vector<long long> &a){
    long long n = a.size();
    vector<long long> dp;
    for (long long i = 0; i < n; ++i){
        long long pos = binSeaLow(dp, a[i]);
        if (pos == dp.size()) {
            dp.push_back(a[i]);
        }else {
            dp[pos] = a[i];
        }
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    long long n;
    cin >> n;
    vector<long long> a(n);
    for (long long i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << DP(a);
    return 0;
}