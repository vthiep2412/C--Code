#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("uoc.inp","r",stdin);
    freopen("uoc.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    vector<long long> uoc;
     for (long long i = 1; i * i <= n; ++i) {
         if (n % i == 0) {
             uoc.push_back(i);
             if (i * i != n) {
                 uoc.push_back(n / i);
             }
         }
     }
     sort(uoc.begin(), uoc.end());
     for (long long x : uoc) cout << x << "\n";
    return 0;
}