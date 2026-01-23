#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("SEQPAIRS.inp","r",stdin);
    freopen("SEQPAIRS.out","w",stdout);
    ll n,m;
	cin>>n>>m;
	vector<ll> a(n),b(m);
	for(ll &x:a)cin>>x;
	for(ll &x:b)cin>>x;
	unordered_map<ll,ll> mp;
	for(int i=0;i<n;i++){
		ll sum=0;
		for(int j=i;j<n;j++){
			sum+=a[j];
			mp[sum]++;
		}
	}
	ll cnt=0;
	for(int i=0;i<m;i++){
		ll sum=0;
		for(int j=i;j<m;j++){
			sum+=b[j];
			if(mp.count(sum)) cnt+=mp[sum];
		}
	}
	cout<<cnt;
    return 0;
}