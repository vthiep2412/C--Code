#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<char> is_prime;

void sieve() {
	ll n = 1e7+5;
    is_prime.assign(n+5, true);
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p)
                is_prime[i] = false;
        }
    }
    return;
}

ll rev(ll n) {
    ll rv = 0;
    while (n > 0) {
        rv = rv * 10 + n % 10;
        n /= 10;
    }
    return rv;
}

bool isprime(ll n){
	if(n<2) return 0;
	return is_prime[n];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("NGUYENTO.INP", "r")){
        freopen("NGUYENTO.INP", "r", stdin);
        freopen("NGUYENTO.OUT", "w", stdout);
    }
    ll n,m;
	cin>>n>>m;
	vector<ll> a(n), pre(n+1, 0);
	vector<char> b(n, 0);
	for(ll &x: a){
		cin>>x;
	}
	sieve();
	for(int i=0;i<n;i++){
		if(isprime(a[i]) and isprime( rev(a[i]) ) ){
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		pre[i] = b[i-1] + pre[i-1];
	}
	while(m--){
        int L, R;
        cin >> L >> R;
        cout << (pre[R] - pre[L-1]) << "\n";
    }
	
    return 0;
}