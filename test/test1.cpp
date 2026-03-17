#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    unordered_map<int,int> sums;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            sums[sum]++;
        }
    }

    return 0;
}