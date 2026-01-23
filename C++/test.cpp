#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    long long n;
    deque<char> d;
    cin >> n;
    while (n > 1) {
        int x = n % 2;
        n /= 2;
        d.push_front(x == 0 ? 'O' : 'A');
    }
    d.push_front('A');
    for (char x : d) {
        cout << x;
    }
    return 0;
}