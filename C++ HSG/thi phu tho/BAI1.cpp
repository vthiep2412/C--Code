#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("BAI1.INP", "r")){
        freopen("BAI1.INP", "r", stdin);
        freopen("BAI1.OUT", "w", stdout);
    }
    ll n, m, x;
	cin>> n>> m>> x;
	ll res1 = (n+x-1) / x;
	ll res2 = (m+x-1) / x;
	
	cout<<res1*res2;

    return 0;
}