#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
#define ld long double
#define pb emplace_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define st first
#define nd second
#define str string

//find lower bound of x in v
ll binSeaLow(vector<ll> &v, ll x){
    ll l = 0, r = v.size();
    while (l < r){
        ll m = l + (r - l) / 2;
        if (v[m] < x){
            l = m + 1;
        }
        else r = m;
    }
    return l;
}


// Longest Increasing Subsequence
// O(n log n)
// By find the lower bound position of each element in dp array
ll DP(const vc<ll> &a){
    ll n = a.size();
    vc<ll> dp;
    for (ll i = 0; i < n; ++i){
        // cout<<"a[i]: "<<a[i]<<"\n";
        ll pos = binSeaLow(dp, a[i]);
        // cout<<"pos: "<<pos<<"\n";
        // cout<<"a[pos]: "<<(pos < dp.size() ? dp[pos] : -1)<<"\n";
        if (pos == dp.size()) {
            dp.push_back(a[i]);
            // cout<<"dp: "<<dp[pos]<<"\n";
        } else {
            dp[pos] = a[i];
            // cout<<"dp: "<<dp[pos]<<"\n";
        }
        cout<<"\n";
    }
    return dp.size();
}

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    ll n;
    cin >> n;
    vc<ll> a(n);
    for (ll i = 0; i < n; ++i){
        cin >> a[i];
    }
    cout << DP(a);
    return 0;
}