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
    freopen("mang07.inp", "r", stdin);
    freopen("mang07.out", "w", stdout);
    int n;
    cin>>n;
    vc<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<a[i]<<" ";
            continue; 
        } else if(a[i-1]<=a[i]){
            cout<<a[i]<<" ";
        } else if (a[i-1]>a[i]){
            cout<<"\n"<<a[i]<<" ";
        }
    }
    return 0;
}