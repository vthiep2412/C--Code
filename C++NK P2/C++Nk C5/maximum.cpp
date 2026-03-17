#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b) {
    return a + b > b + a;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MAXNUM.INP", "r", stdin);
    freopen("MAXNUM.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; ++i) cin >> s[i];

    sort(s.begin(), s.end(), cmp);

    string res;
    for (auto &x : s) res += x;

    if (res[0] == '0') res = "0";

    cout << res << '\n';
    return 0;
}
