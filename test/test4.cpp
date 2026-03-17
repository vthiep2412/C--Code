#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

void solve(){
    int x;
    cin>>x;
    vector<int> r8(201,0),r6(201,0),p10(201,1);
    p10[0] = 1 % X;
    for (int k = 1; k <= 200; k++) {
        p10[k] = (p10[k-1] * 10) % X;
        r8[k] = (r8[k-1] * 10 + 8) % X;
        r6[k] = (r6[k-1] * 10 + 6) % X;
    }
    for(int l = 1; l <= 200; l++){
        for(int n8 = 1; n8 <= l;n8++){
            int n6= l-n8;
            int val = ((r8[n8] * p10[l] + r6[n6]) % X) == 0;
            if(val){
                while(n8--){
                    cout<<"8";
                }
                while(n6--){
                    cout<<"6";
                }
                cout<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
