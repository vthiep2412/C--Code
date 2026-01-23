#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("anasum.INP", "r", stdin);
    freopen("anasum.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long res = 1;
    for (long long x : a) {
        if (x > res) break;
        res += x;
    }
    cout << res;
    return 0;
}


//2 1 17 3 15 7
// 1 2 3 7 15 17
// res = 1
// x = 1
// res = 2
// x = 2
// res = 4
// x = 3
// res = 7
// x = 7
// res = 14
// x = 15
// stop


// res = 30
// x = 17
// res = 47