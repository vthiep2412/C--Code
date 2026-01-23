#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> fib(46);

void makefib(){
	fib[0] = 1;
	fib[1] = 1;
	for(int i=2;i<fib.size();i++){
		fib[i] = fib[i-2]+fib[i-1];
	}
}

char getchar(ll n, ll k){
	while(n>1){
		if(k <= fib[n-2]){
			n-=2;
		}else{
			k-=fib[n-2];
			n-=1;
		}
	}
	return (n == 0 ? 'a' : 'b');
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("FIB1.INP", "r")){
        freopen("FIB1.INP", "r", stdin);
        freopen("FIB1.OUT", "w", stdout);
    }
    ll t;
	cin>>t;
	makefib();
	while(t--){
		ll x, y;
		cin>>x>>y;
		cout<<getchar(x,y)<<"\n";
	}

    return 0;
}