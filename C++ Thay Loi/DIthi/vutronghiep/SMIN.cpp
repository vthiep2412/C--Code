#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("SMIN.inp", "r", stdin);
    freopen("SMIN.out", "w", stdout);
    int n, minsum=INT_MAX, sum=0, r = 0, l = 0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n-1;i++) {
        sum = 0;
        sum += a[i] + a[i+1];
        if(minsum > sum){
            r = i;
            l = i+1;
        }
        minsum = min(minsum, sum);
    }
    cout<<minsum;
    cout<<"\n"<<r+1<<" "<<l+1;
    return 0;
}