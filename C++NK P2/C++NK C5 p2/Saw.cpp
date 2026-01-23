#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("saw.inp", "r", stdin);
    freopen("saw.out", "w", stdout);
    ll n,k;
    cin>>n>>k;
    vector<ll> a(n) , b(k);
    for (ll &i:a) cin>>i;
    for (ll &i:b) cin>>i;
    
    sort(all(a));

    vector<ll> ps(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        ps[i + 1] = ps[i] + a[i];
    }
    
    auto get_wood = [&](ll height) {
        auto it = upper_bound(all(a), height);
        ll p = distance(a.begin(), it);
        ll count = n - p;
        ll sum_of_heights = ps[n] - ps[p];
        return sum_of_heights - count * height;
    };

    for(auto &x : b){
        ll low = 0, high = a.empty() ? 0 : a.back(), ans = 0;
        while(low <= high){
            ll mid = low + (high - low) /2;
            if(get_wood(mid) >= x){
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout<<ans<<" ";
    }
    return 0;
}