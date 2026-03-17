#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

bool check(int n){
    int x = sqrt(n);
    if(x*x==n) return true;
    return false; 
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("mang09.inp", "r", stdin);
    freopen("mang09.out", "w", stdout);
    int n;
    cin>>n;
    vc<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0,mcnt=INT_MIN;
    for(int i=0;i<n;i++){
        if(check(a[i])){
            cnt++;
        } else {
            if(cnt>mcnt) mcnt=cnt;
            cnt=0;
        }
    }
    cout<<mcnt;
    return 0;
}