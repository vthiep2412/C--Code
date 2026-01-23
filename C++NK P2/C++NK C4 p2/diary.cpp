#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long
int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("diary.inp", "r", stdin);
    freopen("diary.out", "w", stdout);
    unordered_set<ll> set;
    ll a,b, res;
    cin >> a >> b;
    if (a>7){
        res = a - 7;
    } else if (b>25) {
        res = b+7;
    }
    return 0;
}