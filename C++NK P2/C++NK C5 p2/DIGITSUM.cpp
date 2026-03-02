#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()

ll toll(string s) {
    stringstream ss(s);
    ll x;
    ss >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("DIGITSUM.INP", "r", stdin);
    freopen("DIGITSUM.OUT", "w", stdout);

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;

        vector<char> a(x);
        for (char &x : a) cin >> x;

        sort(all(a));

        int z = 0;
        while (z < x && a[z] == '0') z++;
		
        string f = "", g = "";
        f += a[z];
        g += a[z + 1];

        bool xorr = 1;

        for (int i = 0; i < z; i++) {
            if (xorr) f += '0';
            else g += '0';
            xorr ^= 1;
        }

        for (int i = z + 2; i < x; i++) {
            if (xorr) f += a[i];
            else g += a[i];
            xorr ^= 1;
        }

        cout << toll(f)+toll(g) << "\n";
    }

    return 0;
}