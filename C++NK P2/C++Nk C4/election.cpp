#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define st first
#define nd second

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("election.inp", "r", stdin);
    freopen("election.out", "w", stdout);
    ll n, m;
    cin >> n >> m;
    vc<ll> ans(n+1,0);
    for(ll i = 1; i <= m; i++ ) {
        ll maxvote = -1;
        ll winGuys = 1;
        for(ll j=1;j<=n;j++){
            ll oi;
            cin>>oi;
            if(oi > maxvote) {
                maxvote = oi;
                winGuys = j;
            }
        }
        ans[winGuys]++;
    }
    ll res=1;
    for(ll i=2;i<=n;i++){
        if(ans[i] > ans[res]) {
            res = i;
        }
    }
    cout << res << "\n";
    return 0;
}