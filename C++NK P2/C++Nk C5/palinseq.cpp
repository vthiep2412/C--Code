#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PALINSEQ.INP", "r", stdin);
    freopen("PALINSEQ.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int l = 0, r = n - 1;
    long long cnt = 0;
    while (l < r) {
        if (a[l] == a[r]) {
            l++;
            r--;
        } else if (a[l] < a[r]) {
            a[l + 1] += a[l];
            l++;
            cnt++;
        } else {
            a[r - 1] += a[r];
            r--;
            cnt++;
        }
    }

    cout << cnt << "\n";
    return 0;
}
