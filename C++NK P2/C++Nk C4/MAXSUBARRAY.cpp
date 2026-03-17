#include <bits/stdc++.h>
using namespace std;

long long maxSubarraySum(const vector<long long>& a) {
    long long curSum = 0, maxSum = INT_MIN;
    for (long long x : a) {
        curSum += x;
        if (curSum > maxSum) {
            maxSum = curSum;
        }
        if (curSum < 0) {
            curSum = 0;
        }
    }
    return maxSum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("MAXSUBARRAY.INP", "r", stdin);
    // freopen("MAXSUBARRAY.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << maxSubarraySum(a) << "\n";
    return 0;
}

// n%2 != 0
// n & 1
