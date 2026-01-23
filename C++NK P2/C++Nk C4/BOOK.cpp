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
 freopen("BOOK.inp", "r", stdin);
 freopen("BOOK.out", "w", stdout);
    ll n;
    cin>>n;
    vc<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    ll sum=0,cnt=0;
    for(ll i=n-1;i>=0;i--){
        if(cnt>=2){
            cnt = 0;
            continue;
        }
        sum+=a[i];
        cnt++;
    }
    cout<<sum;
    return 0;
}