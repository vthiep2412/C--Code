#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BOXES.inp", "r", stdin);
    freopen("BOXES.out", "w", stdout);
    int n,m,sum=0;
    map<int,int> map;
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        int nhap1,nhap2;
        cin>>nhap1>>nhap2;
        if((nhap2 <= m) && (nhap2 > 0)){
            if(map[nhap2] < nhap1){
                sum -= map[nhap2];
                sum += nhap1;
                map[nhap2] = nhap1;
                continue;
            }
        }
    }
    cout<<sum;
    return 0;
}