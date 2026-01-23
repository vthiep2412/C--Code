#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int fp=-1,lp=-1;
    for(int i=0;i<n;i++){
        if(a[i]<0){
            if(fp==-1){
                fp=i;
            }
            lp=i;
        }
    }
    cout<<fp<<" "<<lp;
    return 0;
}