#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void hehe(bool &x){
	if(x) x = false;
	else x = true;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("KILLINGSEQ.inp","r",stdin);
    freopen("KILLINGSEQ.out","w",stdout);
    ll n;
    cin>>n;
	vector<ll> a(n);
	for(ll &x:a)cin>>x;
	sort(a.begin(),a.end());
	bool x = (n % 2 == 0);
	ll l, r;
	if(x){
	    l = (a.size()-1)/2;
	    r = l+1;
	} else {
	    r = (a.size()-1)/2;
	    l = r - 1;
	}
	while(l >= 0 or r < a.size()){
		if(x){
    		if(l >= 0){
    			cout<<a[l]<<" ";
    			l--;
		    }
			hehe(x);
		} else{
		    if(r < a.size()){
			    cout<<a[r]<<" ";
			    r++;
		    }
			hehe(x);
		}
	}
    return 0;
}