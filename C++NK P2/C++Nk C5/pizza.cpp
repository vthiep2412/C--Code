#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<long long,long long>& a, const pair<long long,long long>& b) {
    long long left = (long long)a.first * b.second;
    long long right = (long long)b.first * a.second;
    if (left != right) return left > right;
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("PIZZA.INP", "r", stdin);
    freopen("PIZZA.OUT", "w", stdout);

    int n, k;
    cin >> n >> k;
    vector<pair<long long,long long>> a;
    a.reserve(n);

    for (int i = 0; i < n; ++i) {
        long long r, c;
        cin >> r >> c;
        a.push_back({r * r, c}); // (diện tích, giá)
    }

    sort(a.begin(), a.end(), cmp);

    long long sum = 0;
    for (int i = 0; i < k; ++i) sum += a[i].second;
    cout << sum << '\n';
    return 0;
}
