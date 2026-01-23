#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld;
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll a1 = INT_MAX,a2=INT_MAX,a3=INT_MAX;
void check(ll a, ll b, ll c){
    vector<ll> v={a,b,c};
    sort(all(v));
    if (v[2]-v[1] == v[1]-v[0]) a1 = v[0], a2 = v[1], a3 = v[2];
}

int binsearch(vector<ll> &v, ll x){
    auto it = lower_bound(all(v), x);
    if (it == v.end()) return -1;
    if (*it == x) return it - v.begin();
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TRIPLE.INP", "r", stdin);
    freopen("TRIPLE.OUT", "w", stdout);

    int n;
    cin>>n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d = a[j]-a[i];
            if (d<0) continue;

            ll need = d + a[j];
            int pos = binsearch(a, need);

            if (pos != -1){
                if((a[i] < a1) 
                or (a[i]==a1 and a[j]<a2) 
                or (a[i]==a1 and a[j]==a2 and a[pos]<a3))
                    check(a[i], a[j], a[pos]);
            }
        }
    }

    if (a1!=INT_MAX and a2!=INT_MAX and a3!=INT_MAX){
        cout<<a1<<" "<<a2<<" "<<a3<<"\n";
    } else cout<<"0 0 0\n";

    return 0;
}
