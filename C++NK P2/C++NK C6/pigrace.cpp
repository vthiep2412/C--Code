#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll binLE(const vector<ll> &a, ll x){
	ll l=0, r = a.size()-1,res=-1;
	while(l<=r){
		ll mid = l + (r-l)/2;
		if(a[mid]>=x){
			res = mid;
			r = mid - 1;
		} else 
			l = mid + 1;
	}
	return res;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("pigrace.INP", "r")){
        freopen("pigrace.INP", "r", stdin);
        freopen("pigrace.OUT", "w", stdout);
    }
    ll n,cnt1=0, cnt2=0;
	cin>>n;
	vector<ll> a,b(n);
	unordered_map<int,int> ma;
	for(int i = 0;i<n;i++){
		ll x;
		cin>>x;
		a.push_back(x);
		ma[x]++;
	}
	sort(a.begin(),a.end());
	for(ll &x:b){
		cin>>x;
		ll tmp = binLE(a, x);
		if(tmp==-1){
			cnt2+= n*3;
			continue;
		}else{
			tmp++;
		}
		ll temp = a[tmp-1];
		if (x == temp){
			cnt1 += 1*ma[x] + (n-(tmp-1+ma[x]))*3;
			//if(tmp == 0) tmp=1;
			cnt2 += 1*ma[x] + (tmp-1)*3;
		}else {
			cnt1 += (n-(tmp-1+ma[x]))*3;
			cnt2 += (tmp-1)*3;
		}
	}
	cout<<cnt1<<" "<<cnt2;
    return 0;
}