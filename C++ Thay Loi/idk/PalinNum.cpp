#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll cpow(ll n, ll m){
    ll res=1;
    while(m){
        if(m&1) res*=n;
        n*=n;
        m>>=1;
    }
    return res;
}

ll getFirstDigit(ll num) {
    //num = abs(num); // Handle negative numbers
    ll digits = log10(num); // Find the number of digits - 1
    return num / cpow(10, digits); // Divide by 10^(digits)
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("BAI1.inp", "r", stdin);
    //freopen("BAI1.out", "w", stdout);
    ll r,l;
    cin>>r>>l;
    ll cnt=0,prev=-1;

    for(ll i=r; i<=l; i++){
        ll first = getFirstDigit(i);
        ll last = i % 10;
        if(first==last){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}