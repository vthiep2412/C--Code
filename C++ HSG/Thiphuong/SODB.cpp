#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool prime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

bool chinhphuong(ll n){
	long long c2 = sqrt(n);
	return (c2*c2) == n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	freopen("SODB.INP", "r", stdin);
	freopen("SODB.OUT", "w", stdout);
    ll n,x,cnt=0;
	cin>>n;
	while(n--){
		cin>>x;
		if(chinhphuong(x) and prime(sqrt(x))){
			cnt++;
		}
	}
	cout<<cnt;
	
    return 0;
}