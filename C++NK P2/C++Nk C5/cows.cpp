#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool better(const pair<ll,ll> &a, const pair<ll,ll> &b) {
    return a.second * b.first > b.second * a.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("COWS.INP", "r", stdin);
    freopen("COWS.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<pair<ll,ll>> v(n);   
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end(), better);

    ll T = 0, ans = 0;
    for (auto ok : v) {   
        ans += T * ok.second;
        T += 2 * ok.first;            
    }

    cout << ans;
    return 0;
}
