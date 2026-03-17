#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

struct e {
    int w, iq, idx;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("dinosaur.inp", "r", stdin);
    //freopen("dinosaur.out", "w", stdout);

    int n;
    cin>>n;
    vector<e> a(n), dp(n,1), pr(n,-1);
    for(int i=0;i<n;i++){
        cin>>a[i].w>>a[i].iq;
        a[i].idx = i+1;
    }

    sort(all(a), [](e x, e y){
        if(x.w != y.w) return x.w < y.w;
        return x.iq > y.iq;
    });

    int maxL = 1, st=-1;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if( a[i].w > a[j].w
            and a[i].iq < a[j].iq 
            and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                pr[i] = j;
            }

            if(dp[i] > maxL){
                maxL = dp[i];
                st = i;
            }
        }
    }

    cout<<maxL<<"\n";
    vector<int> res;
    while(st!=-1){
        res.push_back(a[st].idx);
        st = pr[st];
    }

    for(int i=res.size()-1;i>=0;i--)
        cout<<res[i]<<" ";
    return 0;
}