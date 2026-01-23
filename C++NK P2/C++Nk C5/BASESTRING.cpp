#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("BASESTRING.INP", "r", stdin);
    freopen("BASESTRING.OUT", "w", stdout);

    string s, t;
    getline(cin, s);
    getline(cin, t);

    if (s + t != t + s) {
        cout << "NO\n";
        return 0;
    }

    long long g = __gcd((long long)s.size(), (long long)t.size());
    cout << s.substr(0, g) << '\n';
    return 0;
}
