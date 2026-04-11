#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("BINARYGEN.INP", "r")) {
        freopen("BINARYGEN.INP", "r", stdin);
        freopen("BINARYGEN.OUT", "w", stdout);
    }

    int n;
    string s;
    cin >> n >> s;

    int i = n - 1;
    while (i >= 0 and s[i] == '1') {
        s[i] = '0';
        i--;
    }

    if (i < 0) 
        cout << -1;
    else {
        s[i] = '1';
        cout << s;
    }

    return 0;
}