#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define unordered_set uset
#define unordered_map umap

int Greedy(int n) {
    int maxFive = n / 5;
    while (maxFive >= 0) {
        int remaining = n - maxFive * 5;
        if (remaining % 3 == 0) {
            return maxFive + remaining / 3;
        }
        maxFive--;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("packages.inp", "r", stdin);
    freopen("packages.out", "w", stdout);
    vector<int> coins = {3, 5};
    int n = 0;
    cin >> n;
    int res = Greedy(n);
    if (res != -1) {
        cout << res;
    }
    else {
        cout << "-1"; 
    }
    return 0;
}