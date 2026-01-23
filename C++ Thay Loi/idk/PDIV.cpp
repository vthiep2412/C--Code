#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> freq;
    int maxa = 0;

    for(int i=0;i<n;i++){
        cin >> a[i];
        freq[a[i]]++;
        maxa = max(maxa, a[i]);
    }

    vector<int> cnt(maxa+1, 0);
    for(int i=1;i<=maxa;i++){
        for(int j=i;j<=maxa;j+=i){
            cnt[i] += freq[j];
        }
    }

    ll ans = 0;
    for(auto &[i,c] : freq){
        int totalDiv = cnt[i]; 
        ans += 1LL * c * (totalDiv - c);       
        ans += 1LL * c * (c - 1) / 2;         
    }

    cout << ans << "\n"; 
    return 0;
}
