#include <bits/stdc++.h>
using namespace std;

int n, sx, sy, a[55][55], d[55][55], dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

bool isGood(int x, int y){
    return (x >= 1 and x<=n) and (y >= 1 and y<=n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("RUNG.INP", "r", stdin);
    freopen("RUNG.OUT", "w", stdout);

    cin >> n >> sx >> sy;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) cin >> a[i][j];

    queue<pair<int, int>> q;
    q.push({sx, sy}); d[sx][sy] = 1;

    while (!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();
        int x=curr.first, y=curr.second;
        if (x == 1 or y == 1
        or x == n or y == n){
            cout << "1\n"<<d[x][y]<<"\n";
            vector<pair<int, int>> path;
            int px = x, py = y;
            while (px != sx or py != sy) {
                path.push_back({px, py});
                for (int i = 0; i < 4; ++i) {
                    int nx = px - dx[i], ny = py - dy[i];
                    if (isGood(nx, ny) 
                    and d[nx][ny] == d[px][py] - 1
                    and a[nx][ny] == a[px][py]) {
                        px = nx; py = ny; 
                        break;
                    }
                }
            }
            path.push_back({sx, sy});
            for(int i=path.size()-1;i>=0;i--) 
                cout << path[i].first << " " << path[i].second << "\n";
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (isGood(nx, ny) 
            and !d[nx][ny] 
            and a[nx][ny] == a[x][y]) {
                q.push({nx, ny}); 
                d[nx][ny] = d[x][y] + 1;
            }
        }
    }
    cout << 0;
    return 0;
}