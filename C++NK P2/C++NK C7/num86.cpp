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
    p10[0] = 1 % x;
    for(int i=1;i<=200;i++){
        p10[i] = (p10[i-1] * 10) % x;
        r8[i] = (r8[i-1] * 10 + 8) % x;
        r6[i] = (r6[i-1] * 10 + 6) % x;
    }
    for(int l=1;l<=200;l++){
        for(int n8=0;n8<=l;n8++){
            int n6 = l-n8;
            if(( 1LL * r8[n8] * p10[n6] + r6[n6]) % x == 0){
                while(n8--) cout<<"8";
                while(n6--) cout<<"6";
                cout<<"\n";
                return;
            }
        }
    }
    cout<<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("NUM86.inp", "r", stdin);
    freopen("NUM86.out", "w", stdout);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
