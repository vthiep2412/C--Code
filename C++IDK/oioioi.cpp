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
    ll k;
    cin >> k;
    ll n = 1,m = k;
    cout<<n<<" "<<m<<"\n";
    ll maxi = INT_MAX;
    pair<ll,ll> ans = {-1,-1};
    while (m > n) {
        ll oi = (n*m)+((n-1)*(m-1));
        cout<<"oi: "<<oi<<"\n";
        if(oi == k*2){
            cout<<n<<" "<<m<<"\n";
            maxi = min(maxi,abs((n)-(m)));
            // cout<<maxi<<"\n";
            ans = {n-1,m-1};
        }
        m--;
        n++;
    }
    cout<< ans.first << " "<< ans.second;
    return 0;
}