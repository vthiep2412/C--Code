#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("CAU1.inp","r",stdin);
    freopen("CAU1.out","w",stdout);
    vector<long long> a(4);
    for(long long i = 0;i<a.size();i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    cout<<a[0]*a[2];
    return 0;
}
