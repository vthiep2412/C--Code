#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxN = 10000005;
int sD[maxN];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("IMPERFECT.INP", "r", stdin);
    freopen("IMPERFECT.OUT", "w", stdout);

    for(ll i=1; i<=maxN/2;i++)
        for(ll j=2*i;j<maxN;j+=i)
            sD[j] += i;

    ll ans=0, a,b;
    cin>>a>>b;

    for(ll i=a;i<=b;i++)
        ans += std::abs(i-sD[i]);
    cout<<ans;
    return 0;
}