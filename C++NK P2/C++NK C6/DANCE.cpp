#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int findFirstGe(const vector<ll>& a, int n, ll x) {
    int l = 0, r = n - 1, res = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] >= x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int findFirstGt(const vector<ll>& a, int n, ll x) {
    int l = 0, r = n - 1, res = n;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (a[mid] > x) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DANCE.INP", "r", stdin);
    freopen("DANCE.OUT", "w", stdout);

    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll x = a[i] + k;
        int pos1 = findFirstGe(a, n, x);
        int pos2 = findFirstGt(a, n, x);
        cnt += (pos2 - pos1);
    }

    cout << cnt;
    return 0;
}