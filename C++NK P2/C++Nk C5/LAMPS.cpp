#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("lamps.inp", "r", stdin);
    // freopen("lamps.out", "w", stdout);

    ll n; cin >> n;
    vector<ll> a(n);
    for (ll i=0;i<n;i++) cin >> a[i];
    
    ll bestLen=0;
    ll l=0;
    umap<ll,ll> freq;
    
    for(ll r=0;r<n;r++){
        freq[a[r]]++;
        while(freq.size() > 2){
            freq[a[l]]--;
            if(freq[a[l]] == 0) {
                freq.erase(a[l]);
            }
            l++;
        }
        if(freq.size() == 1){
            bestLen = max(bestLen, r-l+1);	
        } else if(freq.size() == 2){
            bool ok=false;
            for(auto &p: freq){
                if(p.second == 1) ok=true;
            }
            if(ok) {
                bestLen = max(bestLen, r-l+1);
            }
        }
    }
    
    cout << bestLen << "\n";
    return 0;
}
