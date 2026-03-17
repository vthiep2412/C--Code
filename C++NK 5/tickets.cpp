#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("TICKETS.INP", "r", stdin);
    freopen("TICKETS.OUT", "w", stdout);
    long long n, k, p1, p2;
    cin >> n >> k >> p1 >> p2;
    long long a,r,N1C1,N1C2,N2C1,N2C2,mini=0;
    a = n / k;
    r = n % k;
    N1C1 = a * p2;
    // cout << N1C1 << "\n";
    N1C2 = (a*k)*p1;
    // cout << N1C2 << "\n";
    mini += min(N1C1,N1C2);
    // cout << mini << "\n";
    // cout<<"----------------\n";
    if(r>k){
        N2C1 = ceil((double)(r/k))*p2;
        cout << N2C1 << "\n";
    } else N2C1 = p2;
    // cout << N2C1 << "\n";
    N2C2 = r*p1;
    // cout << N2C2 << "\n";
    mini += min(N2C1,N2C2);
    cout << mini;
    return 0;
}   