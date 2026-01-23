#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

vector<ll> getDivisors(ll n) {
    vector<ll> divisors;
    for (ll i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    return divisors;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("TINHTONG.inp", "r", stdin);
    //freopen("TINHTONG.out", "w", stdout);
	long long n,cnt=0;
	cin>>n;
	vector<ll> oi = getDivisors(n);
	for(ll &i:n){
		if(i%2!=0){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}