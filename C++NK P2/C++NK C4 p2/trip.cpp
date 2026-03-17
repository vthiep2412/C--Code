#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("trip.inp", "r", stdin);
    freopen("trip.out", "w", stdout);
    long long n, d,cnt=0;
    while(cin>>n>>d) {
        long long temp = d;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        long long l = 0, r = n-1;
        while (l <= r) {
            if(a[l]+a[r]<=d) {
                l++;
                r--;
            }
            else r--;
            cnt++;
        }
        cout<<cnt<<"\n";
        cnt = 0;
    }
    return 0;
}