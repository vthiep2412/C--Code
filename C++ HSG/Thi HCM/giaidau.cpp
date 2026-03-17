#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("giaidau.inp", "r", stdin);
    //freopen("giaidau.out", "w", stdout);
    ll n,q;
    cin>>n>>q;
    vector<ll> a(n);
    vector<ll> preS(n+1);
    preS[0]=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        preS[i+1]=preS[i]+a[i];
    }
    while(q--){
        ll l,r;
        cin>>l>>r;
        ll ttSum = preS[r]-preS[l-1];
        ll lo = l, hi = r-1;
        ll k=l;
        while(lo<=hi){
            ll mid = lo+(hi-lo)/2;
            if(preS[mid] - preS[l-1] <= ttSum/2){
                k = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }

        ll diff1 = abs((preS[k]-preS[l-1]) - (preS[r]-preS[k]));
        if(k+1 > r) cout<<diff1<<"\n";
        else{
            ll diff2 = abs((preS[k+1]-preS[l-1]) - (preS[r]-preS[k+1]));
            cout<<min(diff1,diff2)<<"\n";
        }
    }
    return 0;
}