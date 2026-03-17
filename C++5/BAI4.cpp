#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BAI4.inp", "r", stdin);
    freopen("BAI4.out", "w", stdout);
    int n,mini=INT_MAX;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int l=0,r=a.size()-1;
    while(l<r){
        int sum=a[l]+a[r];
        mini=min(mini,abs(sum));
        if(sum<0) l++;
        else r--; 
    }
    cout<<mini;
    return 0;
}
