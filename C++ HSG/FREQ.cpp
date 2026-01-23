#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FREQ.inp", "r", stdin);
    freopen("FREQ.out", "w", stdout);
    int n,nhap;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> nhap;
        mp[nhap]++;
    }
    int maxi = INT_MIN;
    int maxnum = INT_MIN;
    for (auto i : mp) {
        if (i.second > maxi || (i.second == maxi && i.first > maxnum)) {
            maxi = i.second;
            maxnum = i.first;
        }
    }
    cout << maxnum << " " << maxi;
    return 0;
}
