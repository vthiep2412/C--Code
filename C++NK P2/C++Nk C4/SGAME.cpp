#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define uns unsigned
#define vc vector
#define uset unordered_set
#define umap unordered_map
#define gcd __gcd
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define st first
#define nd second

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SGAME.inp", "r", stdin);
    freopen("SGAME.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];

    long long even = 0, odd = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 0) {
            even += n - i + 1;
        } else {
            odd += n - i + 1;
        }
    }
    cout << even << " " << odd << "\n";
    return 0;
}
