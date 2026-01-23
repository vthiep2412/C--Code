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
    ll n,k;
	cin>>n>>k;
	vector<ll> a(n), pre(n);
	map<ll,ll> mp;
	for(ll &x : a){
		ll tmp;
		cin>>tmp;
		x = (tmp - k);
	}
	pre[0] = a[0];
	for(int i=1;i<n;i++){
		pre[i] = a[i] + pre[i-1];
	}
	ll ending = 0, starting = 0;
	for(int i=0;i<n;i++){
		if(!mp.count(pre[i])){
			mp[pre[i]] = i;
		}
		if(starting > mp[pre[i]]){
			starting = mp[pre[i]];
			ending = i;
		}
	}
	cout<<ending - starting + 1<< stating + 1;
    return 0;
}