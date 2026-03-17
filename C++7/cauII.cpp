#include <bits/stdc++.h>
using namespace std;

int sumofint(int n){
    int sum = 0;
    while(n>0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n;
    cin>>n;
    int res = sumofint(n);
    cout<<res;
    return 0;
}