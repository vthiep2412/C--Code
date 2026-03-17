#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define unordered_set uset
#define unordered_map umap

const ll llhigh = 1e10;

ll slg(ll a, ll b) {
    int cnt = 0;
    if (a < b) return llhigh;
    if (a == b) return 0;
    while(a>b){
        a = (a+1)/2;
        cnt++;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("folding.inp", "r", stdin);
    freopen("folding.out", "w", stdout);
    ll a, b, a1, b1;
    cin >> a >> b >> a1 >> b1;
    ll ans = min((slg(a, a1)+slg(b, b1)),(slg(a, b1)+slg(b, a1)));
    (ans >= INT_MAX || ans < 0) ? cout << -1 : cout << ans;
    return 0;
}