#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vc vector

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("AIRPLANE.inp", "r", stdin);
    freopen("AIRPLANE.out", "w", stdout);
    ld m,n,a;
    cin >> m >> n >> a;
    ld sum = m;
    if(a>=1000){
        cout << "Impossible";
        return 0;
    }
    for(ll i=0;i<n;i++){
        ld x;
        cin >> x;
        sum += x;
    }
    ld res = (a*sum)/(1000-a);
    (res > 0)?cout<<fixed<<setprecision(6)<<res<<"\n" : cout<<"Impossible";
    return 0;
}