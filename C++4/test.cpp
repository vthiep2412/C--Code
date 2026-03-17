#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n;
    cin>>n;
    for (int i = 1; i <= n*n; i++) {
        cout<<i<<" "<<i+1<<" "<<i+2<<" ";
    }
    
    return 0;
}