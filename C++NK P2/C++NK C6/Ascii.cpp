#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("ASCII.inp","r",stdin);
    freopen("ASCII.out","w",stdout);
    ll n,m;
    cin>>n>>m;
    vector<vector<char>> a(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    double res=0;
    for(int i=0;i<n;i++){
        bool isgood = 0;
        for(int j=0;j<m;j++){
            if(a[i][j] == '\\' or a[i][j] == '/'){
                isgood ^= 1;
                res+=0.5;
			}
            if(a[i][j] == '.' and isgood){
                res+=1;
            }
        }
    }
    cout<< res;
    return 0;
}