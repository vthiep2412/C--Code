#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> maze;
vector<vector<int>> best;
int minStep = INT_MAX;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int step) {
    if (step >= best[x][y]) return;
    best[x][y] = step;

    if (x == n-1 && y == m-1) {
        minStep = min(minStep, step);
        return;
    }

    for (int d = 0; d < 4; ++d) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
            dfs(nx, ny, step + 1);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    maze.assign(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> maze[i][j];
    if (maze[0][0] == 1 || maze[n-1][m-1] == 1) {
        cout << -1;
        return 0;
    }
    best.assign(n, vector<int>(m, INT_MAX));
    dfs(0, 0, 0);
    cout << (minStep == INT_MAX ? -1 : minStep);
    return 0;
}
