#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("cdiv.inp", "r", stdin);
    freopen("cdiv.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> cnt(1e6+1,0);
    for(int i=0;i<n;++i){
        cin >> a[i];
        cnt[a[i]]++;
    }
    for(int i = cnt.size()-1;i>=1;--i){
        ll ans=0;
        for(int j = i;j<cnt.size();j+=i){
            ans += cnt[j];
        }
        if(ans>=2){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}