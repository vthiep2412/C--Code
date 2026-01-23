#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> oioi;

pair<ll, int> getCnt(int i, ll k, const vector<ll>& v) {
    ll target = v[i] + k;
    auto lb = v.begin() + i; 
    auto ub = upper_bound(lb, v.end(), target);
    ll cnt = (ll)(ub - lb);
    int idx = (int)(ub - v.begin()) - 1;
    return {cnt, idx};
}

void findTwoMaxSum(const vector<ll>& v) {
    ll n = v.size();
    ll sum = 0;
    if (n < 2) {
        sum = (n == 1) ? v[0] : 0;
        cout << sum;
        return;
    }
    ll m1 = LLONG_MIN, m2 = LLONG_MIN;
    for (const ll& x : v) {
        if (x > m1) {
            m2 = m1;
            m1 = x;
        } else if (x > m2) {
            m2 = x;
        }
    }
    sum = m1 + m2;
    cout << sum;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);

    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        pair<ll, int> oi = getCnt(i, k, a);
        if (oi.first >= 2) {
            oioi.push_back(oi.first);
            i = oi.second; 
        }
    }

    findTwoMaxSum(oioi);
    return 0;
}