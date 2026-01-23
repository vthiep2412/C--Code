#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

bool cmp(pair<int, int> x, pair<int, int> y) {
    return x.first < y.first;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("reward.inp", "r", stdin);
    freopen("reward.out", "w", stdout);
    int n;
    cin>>n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(all(a), cmp);
    ll res = 0, curTime = 0;
    for(auto i : a){
        curTime += i.first;
        res += i.second - curTime;
    }
    cout << res;
    return 0;
}