#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen(".INP", "r")){
        freopen(".INP", "r", stdin);
        freopen(".OUT", "w", stdout);
    }
    ll cnt=0, n,m, maxi = INT_MIN, mini = INT_MAX;
	cin>>n>>m;
	vector<vector<ll>> a(n, vector<ll>(m));
	vector<bool> badx(n), bady(m), badx2(n), bady2(m);
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j] > maxi){
				maxi = a[i][j];
				badx.assign(n, 0); bady.assign(m, 0);
				badx[i] = true; bady[j] = true;
			}
			else if(a[i][j] == maxi){
				badx[i] = true; bady[j] = true;
			}
			if(a[i][j] < mini){
				mini = a[i][j];
				badx2.assign(n, 0); bady2.assign(m, 0);
				badx2[i] = true; bady2[j] = true;
			}
			else if(a[i][j] == mini){
				badx2[i] = true; bady2[j] = true;
			}
		}
	}
	for(ll i=0;i<n;i++){
		for(ll j=0;j<m;j++){
			if( badx[i] or bady[j] or badx2[i] or bady2[j]) continue;
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}