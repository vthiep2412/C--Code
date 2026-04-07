#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

bool vis[1005][1005];
char a[1005][1005];
int m, n;

int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

void dfs(int r, int c) {
    stack<pair<int, int>> st;
    
    st.push({r, c});
    vis[r][c] = 1;

    while (!st.empty()) {
        pair<int, int> curr = st.top();
        st.pop();
        
        int cr = curr.first;
        int cc = curr.second;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dx[i];
            int nc = cc + dy[i];

            if (nr >= 0 and nr < m and nc >= 0 and nc < n 
                and a[nr][nc] == '*' and not vis[nr][nc]) {
                vis[nr][nc] = 1;
                st.push({nr, nc});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("area.inp", "r", stdin);
    freopen("area.out", "w", stdout);
    cin>>m>>n;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            cin>>a[i][j];

    int ans = 0;
    for (int i=0; i<m; i++)
        for (int j=0; j<n; j++)
            if (a[i][j]=='*' and !vis[i][j]) {
                ans++;
                dfs(i, j);
            }
    cout<<ans<<"\n";
    return 0;
}