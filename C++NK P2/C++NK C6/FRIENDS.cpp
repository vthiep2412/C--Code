#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	freopen("FRIENDS.inp","r",stdin);
    freopen("FRIENDS.out","w",stdout);
	map<int, int> mp;
	int n, k, x, cnt=0;
	cin>>n>>k;
	while(n--){
		cin>>x;
		int oi = k - x;
		if (mp.count(oi))
			cnt+=mp[oi];
		mp[x]++;
	}
    cout<<cnt;
    return 0;
}