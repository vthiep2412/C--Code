#include <bits/stdc++.h>
using namespace std;

long long getNum(long long x, long long t, long long v) {
    long long d = v * t;
    long long c = x / d;
    long long r = x % d;
    if (r == 0) return (c * 2 * t - t) * v;
    return (c * 2 * t) * v + r;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("RACING.INP", "r")){
        freopen("RACING.INP", "r", stdin);
        freopen("RACING.OUT", "w", stdout);
    }

    long long t1, v1, t2, v2, x;
    cin >> t1 >> v1 >> t2 >> v2;
    cin >> x;

    long long n1 = getNum(x, t1, v1);
    long long n2 = getNum(x, t2, v2);

    long long lhs = n1 * v2;
    long long rhs = n2 * v1;

    if (lhs < rhs) cout << "First";
    else if (lhs > rhs) cout << "Second";
    else cout << "Draw";

    return 0;
}