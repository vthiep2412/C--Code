#include <bits/stdc++.h>
using namespace std;

int cntline(const vector<int>& words, int w) {
    int lines = 1;
    int currW = 0;
    for (int x : words)
        if (currW == 0)
            currW = x;
        else if (currW + 1 + x <= w)
            currW += 1 + x;
        else {
            lines++;
            currW = x;
        }
    return lines;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("report.inp","r",stdin);
    freopen("report.out","w",stdout);

    int W, n1, n2;
    cin >> W >> n1 >> n2;

    vector<int> a(n1), b(n2);
    int maxA = 0, maxB = 0;

    for (int i = 0; i < n1; i++) {
        cin >> a[i];
        maxA = max(maxA, a[i]);
    }
    for (int i = 0; i < n2; i++) {
        cin >> b[i];
        maxB = max(maxB, b[i]);
    }
    int l = maxA, r = W-maxB;
    int bestAns = INT_MAX;

    while(l <= r){
        int mid = l + (r-l)/2;
        int n = cntline(a, mid), m = cntline(b, W-mid);
        bestAns = min(bestAns, max(n,m));

        if(n < m)
            r = mid - 1;
        else if (n > m)
            l = mid + 1;
        else
            break;
    }

    cout << bestAns;
    return 0;
}