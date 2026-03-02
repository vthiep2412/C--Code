#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getDivisors(int n) {
    ll sum=0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            sum+=i;
            if (i != n / i)
                sum+=(n / i);
        }
    }
    return sum-n;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    if(fopen("ANUM.INP", "r")){
        freopen("ANUM.INP", "r", stdin);
        freopen("ANUM.OUT", "w", stdout);
    }
    ll n;
	cin>>n;
	for(ll i=n;i<=10000;i++){
		ll sum=getDivisors(i);
		if(sum>i){
			cout<<i;
			return 0;
		}
	}
    return 0;
}