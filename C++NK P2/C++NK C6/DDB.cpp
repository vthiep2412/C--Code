#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> etha(ll maxn){
	maxn = maxn*2;
	vector<char> res(maxn+1, 1);
	res[0]=res[1]=0;
	for(ll i=2;i*i<=maxn;i++){
		if(res[i]) 
			for(ll j=i*i; j<=maxn; j+=i) 
				res[j] = 0;
	}
	vector<int> prefix(maxn+1, 0);
	for(int i=1; i<=maxn; i++) 
		prefix[i] = prefix[i-1] + res[i];
	return prefix;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("DDB.INP", "r")){
        freopen("DDB.INP", "r", stdin);
        freopen("DDB.OUT", "w", stdout);
    }
    ll n,maxn=INT_MIN;
	cin>>n;
	vector<ll> a(n);
	for(ll &x:a) {cin>>x; maxn = max(maxn, x);}
	vector<int> pre = etha(maxn);
	for(ll x:a){
		cout<<pre[2*x] - pre[x]<<"\n"; 
	}
    return 0;
}