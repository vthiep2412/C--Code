#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FRACTION.INP", "r", stdin);
    freopen("FRACTION.OUT", "w", stdout);

    long long n;
    cin >> n;

    long long k = n + 1;
    long long r = 1, s = 1;

    string b;
    while (k > 0) {
        b.push_back((k & 1) + '0');
        k >>= 1;
    }
    reverse(b.begin(), b.end());
    b.erase(b.begin());

    for (char c : b) {
        if (c == '0') {
            s = r + s;
        } else {
            r = r + s;
        }
    }

    cout << r << " " << s;

    return 0;
}
