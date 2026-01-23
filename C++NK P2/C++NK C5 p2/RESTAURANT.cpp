#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()

struct eee {
    int time;
    int change;
};

bool cmp (const eee &x, const eee &y) {
    if (x.time == y.time) return x.change < y.change;
    return x.time < y.time;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("RESTAURANT.inp", "r", stdin);
    freopen("RESTAURANT.out", "w", stdout);
    int n;
    cin>>n;
    vector<eee> a;
    a.reserve(2*n);
    for(int i = 0; i < n; i++) {
        int x,y;
        cin>>x>>y;
        a.push_back({x,+1});
        a.push_back({y,-1});
    }
    sort(all(a), cmp);
    ll sum = 0, maxi = 0;
    for(auto &i : a) {
        sum += i.change;
        maxi = max(maxi, sum);
    }
    cout<<maxi;

    return 0;
}