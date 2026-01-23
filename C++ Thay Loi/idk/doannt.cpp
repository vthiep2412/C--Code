#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
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

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    freopen("doannt.inp", "r", stdin);
    freopen("doannt.out", "w", stdout);
    long long n,u,v,cnt;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>u>>v;
        cnt = 0;
        for(ll j=u;j<=v;j+=2){
            if(j%2==0){
                if(j!=2){
                    cnt++;
                    j++;
                }
            }
            if(prime(j)){
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}