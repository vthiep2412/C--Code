#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("sumx.inp", "r", stdin);
    freopen("sumx.out", "w", stdout);
    int m,n,x;
    cin>>m>>n>>x;
    vector<int> a(m);
    for(int i=0;i<m;i++) cin>>a[i];
    map<int,int> map;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        map[tmp]++;
    }
    int cnt=0;
    for(int i=0;i<m;i++){
        int diff = x-a[i];
        if(map.find(diff)!=map.end()){
            cnt+=map[diff];
        }
    }
    cout<<cnt;
    return 0;
}