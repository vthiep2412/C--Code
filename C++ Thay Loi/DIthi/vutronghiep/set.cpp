#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("set.inp", "r", stdin);
    //freopen("set.out", "w", stdout);
    int n,temp;
    cin>>n;
    if(n%2==0){
        cout<<0;
        return 0;
    }
    vector<int> a(n);
    umap<int,int> map;
    for(int i = 0;i<n;i++){ 
        cin>>temp;
        map[temp]++;
        if(map[temp] < 2){
            a[i] = temp;
        }
    }
    sort(all(a));
    ll halfI = a.size()/2;
    ll half = a[halfI];
    ll r=halfI,l=halfI;
    ll cnt1 = 0,cnt2 = 0;
    while(r<n&&a[r]!=half){
        r++;
        cnt1++;
    }
    while(l>=0&&a[l]!=half){
        l--;
        cnt2++;
    }
    if(cnt1==cnt2 and cnt1!=0){
        cout<<1;
    }else{
        cout<<0;
    }
    return 0;
}