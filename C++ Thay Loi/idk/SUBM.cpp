#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("MAXSUBARRAY.INP", "r", stdin);
    // freopen("MAXSUBARRAY.OUT", "w", stdout);
    int n,p,q,cnt=0;
    cin >> n>>p>>q;
    long long curSum = INT_MIN, maxSum = INT_MIN;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (curSum < 0){
            curSum = x;
            cnt=1;
        }
        else {
            curSum += x;
            cnt++;
        }
        if (cnt>=p && cnt<=q){
            maxSum = max(maxSum, curSum);
        }
    }
    cout << maxSum << "\n";
    return 0;
}

// n%2 != 0
// n & 1
