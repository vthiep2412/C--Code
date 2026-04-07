#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

struct e {
    int st,en, idx;
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("overlap.inp", "r", stdin);
    freopen("overlap.out", "w", stdout);
    int n;
    cin>>n;
    vector<e> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].st>>a[i].en;
        a[i].idx = i+1;
    }
    sort(all(a), [](const e& x, const e& y) {
        if (x.en != y.en) return x.en < y.en;
        return x.st < y.st;
    });

    int maxL = 1, st=0;
    vector<int> dp(n,1), pr(n,-1);
    for(int i=0;i<n;i++) {
        for(int j=0;j<i;j++)
            if(a[i].st == a[j].en and dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                pr[i] = j;
            }
        if(dp[i] > maxL){
            maxL = dp[i];
            st = i;
        }
    }

    cout<<maxL<<"\n";
    vector<int> ans;
    while(st != -1){
        ans.push_back(a[st].idx);
        st = pr[st];
    }
    for(int i = ans.size()-1; i>=0; i--)
        cout<<ans[i]<<"\n";
    return 0;
}

/*

5
2 7
1 2
7 9
9 18
18 40

1 2
2 7
7 9
9 18
18 40

6
1 2
10 11
2 3
11 12
3 4
12 13

*/