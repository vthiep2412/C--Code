#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BONUS.inp", "r", stdin);
    freopen("BONUS.out", "w", stdout);
    unordered_map<ll, ll> um;
    ll n;
    cin >> n;
    ll nhap, sum = 0,mn=INT_MAX;
    for(ll i = 0; i < n; i++) {
        cin >> nhap;
        um[nhap] += nhap;
        sum += nhap;
    }
    for(auto i:um){
        mn = min(mn, i.second);
    }
    cout<<sum-mn;
    return 0;
}
