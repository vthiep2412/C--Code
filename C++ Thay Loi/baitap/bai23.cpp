#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(b) b.begin(), b.end()

struct e {
    ll val=0, cnt=0, idx=1e18;
};

bool cmp1(e a, e b) {
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.val < b.val;
}

bool cmp2(e a, e b) {
    if (a.cnt != b.cnt) return a.cnt > b.cnt;
    return a.idx < b.idx;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll n,x;
    cin >> n;
    vector<ll> a(n);
    map<ll, e> mp;

    for (int i = 0; i < n; i++) {
        cin >> x;
        a[i] = x;
        mp[x].val = x;
        mp[x].cnt++;
        if (mp[x].idx == 1e18) {
            mp[x].idx = i;
        }
    }

    vector<e> b;
    for (pair<ll, e> oi : mp) b.push_back(oi.second);

    sort(all(b), cmp1);
    for (e &x : b) 
        for (int i=0; i<x.cnt; i++)
            cout<<x.val<<" ";
    cout<<"\n";

    sort(all(b), cmp2);
    for (e &x : b) 
        for (int i=0; i<x.cnt; i++)
            cout<<x.val<<" ";

    return 0;
}