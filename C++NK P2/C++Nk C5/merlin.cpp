#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("merlin.inp", "r", stdin);
    freopen("merlin.out", "w", stdout);
    ll n,sum=0,s1,s2,ans=0,temp=0;
    cin>>n;
    vector<ll> a(n+1);
    a[0]=0;
    for(ll i = 1;i<=n;++i){
        cin>>a[i];
        sum+=a[i];
    }
    sort(all(a));
    for(ll i = 0;i<=n;++i){
        s1=sum-temp-a[i];
        s2=a[i]*i- (sum - s1);
        if(s1>=s2){
            ans = n-i;
        }
        temp+=a[i];
    }
    cout<<ans;
    return 0;
}