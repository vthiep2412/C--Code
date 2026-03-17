#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fib(46), Ta(46);

void makefib(){
	fib[0] = 1;
	fib[1] = 1;
	Ta[0] = 1;
	Ta[1] = 0;
	for(int i=2;i<fib.size();i++){
		fib[i] = fib[i-2]+fib[i-1];
		Ta[i] = Ta[i-2] + Ta[i-1];
	}
}

ll getnum(ll n, ll k){
	if (n == 0) return 1;
    if (n == 1) return 0;
    if (k == 0) return 0;
	if (k >= fib[n-2]) return a[n-2] + getnum(n-1, k - fib[n-2]);
	return getnum(n-2, k);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("FIB2.INP", "r")){
        freopen("FIB2.INP", "r", stdin);
        freopen("FIB2.OUT", "w", stdout);
    }
    ll t;
	cin>>t;
	makefib();
	while(t--){
		ll x, y;
		cin>>x>>y;
		cout<<getnum(x,y)<<"\n";
	}

    return 0;
}