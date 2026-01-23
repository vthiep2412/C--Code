//day so
//slow way
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    ll n,L,R;
    cin >> n >> L >> R;
    vc<ll> a(n);
    for (ll i = 0;i < n;i++) cin >> a[i];
    ll maxi = LLONG_MIN;
    ll cnt = R;
    while(cnt != L){
        for(int i = 0; i< n - cnt;i++){
            ll sum = a[i]+a[i+1]+a[i+2];
            // cout << sum << "\n";
            // cout<<a[i] << a[i+1] << a[i+2] << "\n";
            maxi = max(maxi,sum);  
        }
        cnt--;
    }
    cout << maxi;
    return 0;
}