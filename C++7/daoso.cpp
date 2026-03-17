#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n;
    cin>>n;
    vector<string> a(0);
    for(int i=0;i<n;i++){
        string nhap;
        cin>>nhap;
        reverse(nhap.begin(),nhap.end());
        a.push_back(nhap);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}