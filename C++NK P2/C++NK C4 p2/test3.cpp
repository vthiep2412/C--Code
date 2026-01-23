#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> a;
long long n, m, ans = 0, sum = 0, cnt = 0;

void loan(int x, int y) {
    a[x][y] = 0;
    if (x + 1 < n && a[x + 1][y] != 0) { sum += a[x + 1][y]; loan(x + 1, y); }
    if (x - 1 >= 0 && a[x - 1][y] != 0) { sum += a[x - 1][y]; loan(x - 1, y); }
    if (y + 1 < m && a[x][y + 1] != 0) { sum += a[x][y + 1]; loan(x, y + 1); }
    if (y - 1 >= 0 && a[x][y - 1] != 0) { sum += a[x][y - 1]; loan(x, y - 1); }
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a.resize(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    ans = 0; sum = 0; cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 0) {
                sum+=a[i][j];
                cnt++;
                loan(i, j);
                ans = max(ans, sum);
                sum = 0;
            }
        }
    }

    cout << ans << " " << cnt;
    return 0;
}
