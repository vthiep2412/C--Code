#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("EMISTA.inp", "r", stdin);
    // freopen("EMISTA.out", "w", stdout);
    ll n,k;
    cin>>n>>k;
    map<ll,ll> events;
    for(ll i=0;i<n;++i){
        ll x,y;
        cin>>x>>y;
        events[x-k] += y;
        events[x+k+1] -= y;
    }
    
    ll maxi = 0;
    ll cursum = 0;
    for(auto const& i : events){
        cursum += i.second;
        maxi = max(maxi, cursum);
    }

    cout<<maxi;
    return 0;
}