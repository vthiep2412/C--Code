#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("DOANCON.inp", "r", stdin);
    // freopen("DOANCON.out", "w", stdout);
    int n,m,sum=0,cnt=0;
    bool check = false;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i]; 
    }
    while(!a.empty()) {
        for(int i=0;i<a.size();i++){
            sum+=a[i];
            if(sum==m){
                cnt++;
                check = true;
                a.erase(a.begin(),a.begin()+i+1);
                break;
            } else if(sum>m){
                break;
            } else if (i==a.size()-1&&sum<m) {
                break;
            }
        }
        if(check==false){
            a.erase(a.begin());
            sum=0;
        } else {
            sum=0;
            check = false;
        }
    }
    cout << cnt;
}