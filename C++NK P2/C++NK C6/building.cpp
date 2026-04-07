#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("building.inp", "r", stdin);
    freopen("building.out", "w", stdout);
    
    int m, n, cnt = 0;;
    cin >> m >> n;

    vector<vector<int>> h(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> h[i][j];
        }
    }

    vector<vector<int>> maxL(m, vector<int>(n, 0));
    vector<vector<int>> maxR(m, vector<int>(n, 0));
    vector<vector<int>> maxU(m, vector<int>(n, 0));
    vector<vector<int>> maxD(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        int curL = 0, curR = 0;
        for (int j = 0; j < n; j++) {
            maxL[i][j] = curL;
            curL = max(curL, h[i][j]);
        }
        for (int j = n - 1; j >= 0; j--) {
            maxR[i][j] = curR;
            curR = max(curR, h[i][j]);
        }
    }

    for (int j = 0; j < n; j++) {
        int curU = 0, curD = 0;
        for (int i = 0; i < m; i++) {
            maxU[i][j] = curU;
            curU = max(curU, h[i][j]);
        }
        for (int i = m - 1; i >= 0; i--) {
            maxD[i][j] = curD;
            curD = max(curD, h[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int curH = h[i][j];
            if (i == 0 or i == m - 1 or j == 0 or j == n - 1) continue;

            if (curH < maxL[i][j] and curH < maxR[i][j] and 
                curH < maxU[i][j] and curH < maxD[i][j]) {
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}