#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000001;
int sD[MAX];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PP.inp", "r", stdin);
    freopen("PP.out", "w", stdout);

    for (int i = 1; i < MAX; ++i)
        for (int j = 2 * i; j < MAX; j+=i)
            sD[j] += i;

    int l, r;
    cin >> l >> r;

    int c = 0;
    for (int i = l; i <= r; ++i)
        if (sD[i] > i)
            c++;

    cout << c << "\n";
    return 0;
}