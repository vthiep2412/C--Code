#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CAYTHONG.INP", "r", stdin);
    freopen("CAYTHONG.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int minS = INT_MAX;
    int r=0,l=n-1;
    while (r < n && l >= 0) {
        minS = min(abs(minS), abs(a[r] + b[l]));
        if (a[r] + b[l] < 0) {
            r++; 
        } else {
            l--; 
        }
    }
    cout << minS;
}