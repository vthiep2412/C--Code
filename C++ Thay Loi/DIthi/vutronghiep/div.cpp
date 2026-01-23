#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

long long countDivisors(long long n){
    long long cnt=0;
    for(long long i=1;i*i<=n;++i){
        if(n%i==0){
            cnt++;
            if(i*i!=n) cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("div.inp", "r", stdin);
    freopen("div.out", "w", stdout);
    ll n;
    cin>>n;
    cout<<countDivisors(n);

    return 0;
}