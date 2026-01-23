#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

long long cpow(long long a, long long b) {
    long long res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

string toSTR(ll x){
    stringstream ss;
    ss << x;
    return ss.str();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("Palindrome.inp", "r", stdin);
    freopen("Palindrome.out", "w", stdout);
    ll n;
    cin >> n;
    vector<string> a;
    for(ll len = 1; a.size() < n; len++){
        ll start = cpow(10, (len - 1) / 2);
        ll end = pow(10, (len + 1) / 2);
        for(ll i = start; i < end and a.size() < n; i++){
            string s = toSTR(i);
            string rev = s;
            reverse(all(rev));
            if(len % 2 == 1) rev.erase(rev.begin());
            a.pb(s + rev);
        }
    }
    cout << a[n - 1];
    return 0;
}