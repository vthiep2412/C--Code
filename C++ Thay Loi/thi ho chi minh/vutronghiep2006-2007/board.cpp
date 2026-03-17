#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(".INP", "r")){
        freopen(".INP", "r", stdin);
        freopen(".OUT", "w", stdout);
    }
    ll n,m,maxS=1,q;
	cin>>n>>m>>q;
	ll curS=min(n,m);
	vector<vector<char>> a(n,vector<char>(m,0));
	while(q--){
		int x,y;
		cin>>x>>y;
		a[x-1][y-1]=1;
	}
	for(int size=curS; size>=0; size--){
		for()
	}
    return 0;
}