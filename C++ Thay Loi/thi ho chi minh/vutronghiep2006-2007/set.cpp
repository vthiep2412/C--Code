#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("SET.INP", "r")){
        freopen("SET.INP", "r", stdin);
        freopen("SET.OUT", "w", stdout);
    }
    ll n;
	cin>>n;
	set<ll> b;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		b.insert(x);
	}
	if(s.size() >=3 and s.size() %2 !=0){
		cout<<1;
	}else cout<<0;
    return 0;
}