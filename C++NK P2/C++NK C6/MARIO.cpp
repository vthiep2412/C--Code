#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MARIO.inp","r",stdin);
    freopen("MARIO.out","w",stdout);
    ll n,res=0;
    cin>>n;
	vector<ll> a(n);
	for(ll &x:a) cin>>x;
	for(int i=n-1; i>=0; i--){
		res = (res + a[i]+1)/2;
	}
	cout<<res;
    return 0;
}