#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll getDivisors(ll n) {
    ll sum = 0;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            sum+=i;
            if (i != n / i) {
                sum+=(n / i);
            }
        }
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("TONGUOC.INP", "r", stdin);
    freopen("TONGUOC.OUT", "w", stdout);
    
    ll a,b,c;
	cin>>a>>b>>c;
	
	cout<<max(a,max(b,c));
    return 0;
}