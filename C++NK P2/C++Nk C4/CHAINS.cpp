#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("chains.inp", "r", stdin);
    freopen("chains.out", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> pref(n+1);
    pref[0] = 0;
    for(int i = 1; i <= n; i++){
        pref[i] = pref[i-1] + a[i-1];
    }
    int ans = n;
    for(int s = 0; s <= n; s++){
        long long S = pref[s];
        long long need = (long long)n - s - 1;  
        if (S >= need) {
            if (S == need) ans = S;
            else ans = n - s;
            break;
        }
    }
    cout << min(ans,n-1) << "\n";
    return 0;
}
