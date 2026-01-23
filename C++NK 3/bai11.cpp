#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("MOBILE.inp", "r", stdin);
    freopen("MOBILE.out", "w", stdout);

    int p, t, n;
    cin >> p >> t >> n;

    int min = n / 60;
    int sec = n % 60;
    int x = min * p;
    int y = (sec + 5) / 6;
    int s = x + (y * t);
    cout << s;
    
    return 0;
}

