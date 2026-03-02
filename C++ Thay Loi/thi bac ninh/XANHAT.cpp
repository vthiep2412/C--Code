#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	freopen("XANHAT.INP", "r", stdin);
	freopen("XANHAT.OUT", "w", stdout);
    ll n,k;
	cin>>n>>k;
	vector<ll> pre(n, -1), a(n);
	cin>>a[0];
	pre[0] = a[0];
	for(int i = 1; i<n; i++){
		cin>>a[i];
		pre[i] = min(a[i], pre[i-1]);
	}
	ll maxi = 0;
	for(int i=0;i<n;i++){
		ll tar = a[i]-k;
		auto it = lower_bound(pre.begin(), pre.begin()+i, tar, greater<long long>());
		if(it != pre.begin()+j and *it <= tar){
			ll oi = distance(pre.begin(), it);
			maxi = max(maxi, i-oi);
		}
	}
	cout<<maxi;
    return 0;
}