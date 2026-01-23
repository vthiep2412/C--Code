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
#define str string

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 freopen("BUYGIFTS.inp", "r", stdin);
 freopen("BUYGIFTS.out", "w", stdout);
    ll n,m,mini=INT_MAX;
    cin >> n >> m;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin>>a[i];
    sort(all(a));
    for(ll i=n-1;i>=0+m-1;i--){
        if(a[i]-a[i-m+1]<mini){
            mini = a[i] - a[i-m+1];
        }
    }
    cout << mini;
    return 0;
}