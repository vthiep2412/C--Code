#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector
#define uset unordered_set
#define umap unordered_map

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("magnets.inp", "r", stdin);
    freopen("magnets.out", "w", stdout);
    int n,cnt=0;
    cin>>n;
    int x;
    cin>>x;
    int prev = x;
    for(int i=1;i<n;i++){
        cin>>x;
        if(x!=prev){
            cnt++;
        }
        prev = x;
    }
    cout<<cnt+1<<"\n";
    return 0;
}