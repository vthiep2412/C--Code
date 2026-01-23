#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define unordered_set uset
#define unordered_map umap

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ird.inp", "r", stdin);
    freopen("ird.out", "w", stdout);
    ll a,b,c,d,x,y,z;
    cin >> a >> b >> c >> d;
    x = (a*d)+(b*c);
    y = b*d;
    z = __gcd(x,y);
    x /= z;
    y /= z;
    cout << x << " " << y;
    return 0;
}