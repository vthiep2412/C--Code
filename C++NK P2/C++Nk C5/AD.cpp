#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("AD.inp", "r", stdin);
    freopen("AD.out", "w", stdout);
    string a, b;
    if (!(cin >> a >> b)) return 0;
    long long cnt = 0;
    unordered_map<unsigned char, int> diff;
    for (unsigned char ch : a) diff[ch]++;
    for (unsigned char ch : b) diff[ch]--;
    for (const auto& kv : diff) cnt += abs(kv.second);
    cout << cnt;
    return 0;
}