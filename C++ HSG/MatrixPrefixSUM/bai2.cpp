#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);
    int n, m, q, x;
	vector<vector<int>> p(n, vector<int>m);
	cin>>n>>m>>q;
	for(int i = 0;i<n;i++) {
		for(int j = 0;j<m;j++) {
			cin>>x;
			p[i][j] = x + p[i-1][j] + p[i][j-1] - p[i-1][j-1]
		}
	}
	
	int x1,x2,y1,y2;
	while(q--){
		cin>>x1>>y1>>x2>>y2;
		cout<<p[x2][y2] - p[x1-1][y2] - p[x1][y2-1] + p[x1-1][y1-1]<<"\n";
	}
    return 0;
}