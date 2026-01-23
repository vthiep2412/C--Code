#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int n,k,x;
    cin>>n>>k;
    map<int,int> a;
    for(int i=1;i<k;i++){
        cin>>x;
        a[x]++;
    }
    int firstI = a.begin()->first, prevI;
    int l1=0,l2=0,ans=INT_MIN;
    for(auto [i,val]:a){
        if(i==firstI){
            prevI=i;
            continue;
        }
        if(i-prevI==1){
            ++l2;
            ans = max(ans, l1+l2);
        } else{
            if(i-prevI==1){
                l1 = l2;
                l2 = 0;
            }else{
                l1 = l2 = 0;
            }
        }
    }
    cout<<ans;
    return 0;
}