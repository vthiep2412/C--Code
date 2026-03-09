#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

int sumDigit(int n) {   
    int res = 0;
    while (n)
        res += n % 10, n /= 10;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("SIMILAR.inp", "r", stdin);
    //freopen("SIMILAR.out", "w", stdout);
    int n,m, best=0;
    cin >> n >> m;
    vector<int> minVal(65, INT_MAX), maxVal(65, INT_MIN);
    for (int i = n; i <= m; i++) {
        int s = sumDigit(i);
        minVal[s] = min(minVal[s], i);
        maxVal[s] = max(maxVal[s], i);
        if (maxVal[s] - minVal[s] > best)
            best = maxVal[s] - minVal[s];
    }
    cout << best;
    return 0;
}