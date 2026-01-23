#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
vc<ll> a;

bool kt(long long n){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    const long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool check(ll n){
    ll sum=0;
    while(n>0){
        ll f=n%10;
        sum+=(f*f);
        n/=10;
    }
    return kt(sum);
}
void build(ll n){
    ll oi = 1, cnt = 1;
    while(cnt<=n){
        if(check(oi)){
            a.pb(oi);
            cnt++;
        }
        oi++;
    }
}
    int main() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        freopen("beauty2.inp", "r", stdin);
        freopen("beauty2.out", "w", stdout);
        ll n,maxi = -1;
        vc<ll> b;
        while(cin>>n){
            maxi = max(maxi,n);
            b.pb(n);
        }
        build(maxi);
        for(auto x: b){
            cout<<a[x-1]<<"\n";
        }
        return 0;
    }