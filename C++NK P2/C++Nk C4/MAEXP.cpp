#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vc vector

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAEXP.inp", "r", stdin);
    freopen("MAEXP.out", "w", stdout);
    ll n;
    cin >> n;
    vc<ll> a(n);
    ll allSum = 0;
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
        allSum += a[i];
    }
    ll mAns = INT_MIN, mAnsCur = INT_MIN, mResCur = INT_MIN;
    for (ll i = 1; i < n - 2; i++) {
        ll stMul = a[i] * a[i-1];
        for (ll j = i + 2; j < n; j++) {
            ll ndMul = a[j] * a[j-1];
            ll ansCur = allSum + stMul + ndMul - a[i] - a[i-1] - a[j] - a[j-1];
            mAnsCur = max(ansCur, mAnsCur);
        }
    }
    for (ll i = 1; i < n - 1; i++) {
        ll oi = a[i-1] * a[i] * a[i+1];
        ll resCur = allSum + oi - a[i-1] - a[i] - a[i+1];
        mResCur = max(mResCur, resCur);
    }
    mAns = max(mAnsCur, mResCur);
    cout << mAns;
    return 0;
}