#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()
struct e{
	ll a,b;
};

bool cmp(e x, e y) {
    if (x.a != y.a) return x.a < y.a;
    return x.b < y.b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("bai5.inp","r",stdin);
    freopen("bai5.out","w",stdout);
    ll n,m, i,r;
	cin>>n>>m;
	vector<ll> a(n);
	vector<e> idx;
	for(ll &x:a) cin>>x;
	while(m--){
		cin>>i>>r;
		ll Llimit = a[i-1] - r;
		ll Rlimit = a[i-1] + r;
		vector<ll>::iterator itL = lower_bound(all(a), Llimit);
		vector<ll>::iterator itR = upper_bound(all(a), Rlimit);
		ll Lidx = distance(a.begin(), itL);
		ll Ridx = distance(a.begin(), itR);
		idx.push_back({Lidx,Ridx});
	}
	
	if (idx.empty()) {
        cout << 0 << "\n";
        return 0;
    }
	
	sort(all(idx),cmp);
	ll sum=0;
	ll curL = idx[0].a;
	ll curR = idx[0].b;
	
	for(ll j=1;j<idx.size();j++){
		if(idx[j].a <= curR){
			curR = max(curR, idx[j].b);
		} else {
			sum += curR-curL;
			curL = idx[j].a;
			curR = idx[j].b;
		}
	}
	sum += curR-curL;
	
	cout<<sum;
    return 0;
}