#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FLY.INP", "r", stdin);
    freopen("FLY.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);
    for (pair<ll,ll> &x:v)
        cin >> x.first;
    ll tW = 0;
    for (int i = 0; i < n; ++i) {
        cin >> v[i].second;
        tW += v[i].second;
    }
    sort(v.begin(), v.end());

    ll curW = 0, p = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        curW += v[i].second;
        if (curW >= (tW + 1)/2) {
            p = v[i].first; break;
        }
    }

    for (int i = 0; i < n; ++i)
        ans += v[i].second * abs(v[i].first - p);
    cout << p << " " << ans << "\n";
    return 0;
}