#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXDIVI.inp", "r", stdin);
    freopen("MAXDIVI.out", "w", stdout);
    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);
    sort(a.begin(), a.end());
    long long g = 0;
    for (int i = 1; i < a.size(); i++){
        g = __gcd(g, llabs(a[i] - a[0]));
    }
    cout << g;
    return 0;
}
