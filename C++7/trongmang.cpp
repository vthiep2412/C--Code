// cách ai biết gì đâu.
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n,m;
    cin>>n>>m;
    int msize=max(n,m);
    vector<int> a(msize,0);
    vector<int> b(msize,0);
    vector<int> res(0);
    for(int i=n-1;i>=0;i--){
        cin>>a[i];
    }
    for(int i=m-1;i>=0;i--){
        cin>>b[i]; 
    }
    while(res.size()!=(n+m)){
        int x = a.back();
        int y = b.back();
        a.pop_back();
        b.pop_back();
        res.push_back(min(x, y));
        res.push_back(max(x, y));
    }
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i]<<" ";
    }

    return 0;
}