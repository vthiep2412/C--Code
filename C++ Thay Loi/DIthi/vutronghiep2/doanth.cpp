#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll n,k,cnt=0,ans=0;

ll calc(ll n){
    return n*(n-1)/2;
}

ll countB(ll r, ll l, string &s){
    if(cnt != k) return 0;
    ll i = r - 1;
    ll j = l + 1;
    ll cnt2=0;
    while(i>=0 and s[i] == 'b') {
        i--;
        cnt2++;
    }
    while(j<s.size() and s[j] == 'b') {
        j++;
        cnt2++;
    }
    return cnt2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("doanth.inp", "r", stdin);
    // freopen("doanth.out", "w", stdout);
    cin>>n>>k;
    string s;
    cin>>s;
    for(int r=0;r<n;++r){
        if(s[r] != 'a'){
            if(cnt>0) cnt--;
            cout<<r<<" "<<cnt<<"\n";
            continue;
        }
        cnt = 1;
        for(ll l=r;l<n;++l){
            if(cnt == k and s[l] == 'a'){
                ans += (calc(countB(r,l,s) + 1) + 1);
                cout<<r<<" "<<l<<" "<<cnt<<"\n";
                cnt--;
                break;
            }
            if(s[l] != 'a'){
                continue;
            } else if (l != r){
                cnt++;
            }
            
            if(cnt == k and s[l] == 'a'){
                ans += (calc(countB(r,l,s) + 1) + 1);
                cout<<r<<" "<<l<<" "<<cnt<<"\n";
                cnt--;
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}