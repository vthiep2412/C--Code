#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()

bool vis[]

int dx[]={-1,1,0,0}, dy[]={0,0,-1,1};

void dfs(int r, int c) {
    if (r<0 || r>=m || c<0 || c>=n || a[r][c]!='*' || vis[r][c]) return;
    vis[r][c] = 1;
    for (int i=0; i<4; i++) dfs(r+dx[i], c+dy[i]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("area.inp", "r", stdin);
    //freopen("area.out", "w", stdout);


    return 0;
}