#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DX.inp", "r", stdin);
    freopen("DX.out", "w", stdout);
    string s;
    cin >> s;
    string str = s;
    reverse(s.begin(), s.end());
    (s == str) ? cout << "YES" : cout << "NO";
    return 0;
}