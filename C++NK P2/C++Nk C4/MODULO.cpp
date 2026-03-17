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
string ToString(ll n){
    stringstream ss;
    ss<<n;
    return ss.str();
}

string superMod(string s, ll k) {
    ll tmp = 0;
    for (char c:s)
        tmp = (tmp * 10 + (c - '0')) % k;
    return ToString(tmp);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
 freopen("MODULO.inp", "r", stdin);
 freopen("MODULO.out", "w", stdout);
    ll n,k;
    cin>>n>>k;
    string s="";
    if(s[0]=='0'){
        while(s[0]=='0') s.erase(0,1);
    }
    while(n--){
        cin>>s;
        cout<<superMod(s,k)<<"\n";
    }
    return 0;
}