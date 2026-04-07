#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("EXcurs.inp", "r", stdin);
    freopen("EXcurs.out", "w", stdout);
    int n, k, distin=0;
    cin>>n>>k;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    map<int,int> mp;
    for(int i=0;i<k;i++){
        if(!mp[a[i]]) distin++;
        mp[a[i]]++;
    }
    int maxdistin = distin;
    int ans = 1;
    for(int i=k;i<n;i++){
        int outCity = a[i-k];
        mp[outCity]--;
        if(!mp[outCity]) distin--;

        int inCity = a[i];
        if(!mp[inCity]) distin++;
        mp[inCity]++;

        if(distin > maxdistin){
            maxdistin = distin;
            ans = (i - k + 1) + 1;
        }
    }
    cout<<ans;
    return 0;
}