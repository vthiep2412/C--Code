#include <iostream>
#include <string>
using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("COUNT.inp", "r", stdin);
    freopen("COUNT.out", "w", stdout);
    long long n,cnt=0;
    cin>>n;
    for (long long i = 1;i<=n;i++) {
        long long a;
        cin>>a;
        if (a%90==0) cnt++;
    }
    cout<<cnt;
    return 0;
}