#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n;
    cin>>n;
    unordered_map<char,int> a;
    for(int i=1; i<=n; i++){
        string s;
        int x;
        cin>>s>>x;
        a[s[0]] += x;
    }
    vector<pair<int, char>> v;
    for(auto p : a) {
        v.push_back({p.second, p.first});
    }
    sort(v.rbegin(), v.rend());
    cout << v[0].second << "\n" << v[1].second;
    return 0;
}

