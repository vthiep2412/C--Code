#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	
    // freopen(".INP", "r", stdin);
    // freopen(".OUT", "w", stdout);

    int n,m,q;
    cin>>n>>m>>q;
    vector<vector<int>> p(n+1,vector<int>(m+1,0));
    for(int i=0;i<q;++i){
        int x,y;
        cin>>x>>y;
        p[x][y]=1;
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            p[i][j]+=p[i-1][j]+p[i][j-1]-p[i-1][j-1];
        }
    }

    for(int s=min(n,m);s>=1;--s){
        for(int i=1;i<=n-s+1;++i){
            for(int j=1;j<=m-s+1;++j){
                int r2=i+s-1;
                int c2=j+s-1;
                int sum=p[r2][c2] - p[i-1][c2] - p[r2][j-1] + p[i-1][j-1];
                if(sum==0){
                    cout<<s*4<<"\n";
                    return 0;
                }
            }
        }
    }

    cout<<0<<"\n";
    return 0;
}