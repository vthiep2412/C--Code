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

ll Round(ld n) {
    ll noDec = static_cast<ll>(n);
    ll noDec2 = floor(n);
    if((n-noDec2 != 0.0) && (n-noDec != 0.0)) return (noDec+1 == ceil(n))?noDec+1:noDec;
    return noDec;
}

ll LastTerm(ll n){
    return Round((-1+sqrt(1+8*n))/2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 freopen("mapping.inp", "r", stdin);
 freopen("mapping.out", "w", stdout);
    ll x,y,z;
    cin>>x>>y>>z;
    ll Lterm = x+y-1;
    Lterm = (Lterm*(Lterm+1))/2;
    ll Diff = x-1;
    cout<<Lterm-Diff<<"\n";
    ll Y = LastTerm(z), X = 1;
    ll Lterm2 = (Y*(Y+1))/2;
    ll Diff2 = (Lterm2 - z);
    cout<<X+Diff2<<" "<<Y-Diff2;
    return 0;
}