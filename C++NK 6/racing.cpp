#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("racing.inp", "r", stdin);
    freopen("racing.out", "w", stdout);
    ll t1,v1,t2,v2,x;
    cin>>t1>>v1>>t2>>v2;
    cin>>x;
    ll res1, res2;
    res1 = ((x/(v1*t1))*(t1*2))-t1;
    res2 = ((x/(v2*t2))*(t2*2))-t2;
    cout << res1 << " " << res2 << endl;
    if(res1<res2) cout << "First";
    else if(res1>res2) cout << "Second";
    else cout << "Draw";
    return 0;
}