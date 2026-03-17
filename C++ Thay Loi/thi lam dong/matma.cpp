#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen(".INP", "r")){
        freopen(".INP", "r", stdin);
        freopen(".OUT", "w", stdout);
    }
    ll n,m;
	cin>>n>>m;
	n%=10;
	long long res = 1;
	while(m>0){
		if(m&1) res = (res*a)%10;
		a = (a*a)%10
		b/=2;
	}
	cout<<res%10;
    return 0;
}