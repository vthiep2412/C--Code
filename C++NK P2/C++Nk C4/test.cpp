#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")
#define ll long long

ll sizecnt=0;
ll dfs(const int &i,const int &j, vector<vector<ll>> &a){
    sizecnt = 0;
    vector<pair<int,int>> stack;
    stack.push_back({i,j});
    a[i][j] = 0;
    ll count = 0;

    while(!stack.empty()){
        auto [x,y] = stack.back();
        stack.pop_back();
        count++;

        if(x-1 >= 0 && a[x-1][y] == 1){
            stack.push_back({x-1,y});
            a[x-1][y] = 0;
        }
        if(x+1 < (int)a.size() && a[x+1][y] == 1){
            stack.push_back({x+1,y});
            a[x+1][y] = 0;
        }
        if(y-1 >= 0 && a[x][y-1] == 1){
            stack.push_back({x,y-1});
            a[x][y-1] = 0;
        }
        if(y+1 < (int)a[0].size() && a[x][y+1] == 1){
            stack.push_back({x,y+1});
            a[x][y+1] = 0;
        }
    }
    return count;
}

ll maxAisland(vector<vector<ll>> &a){
    ll maxS=-1;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < a[i].size(); j++){
            if(a[i][j]==1){
                maxS=max(maxS,dfs(i,j,a));
            }
        }
    }
    return maxS;
}

int main() {
    ios_base::sync_with_stdio(0);    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    vector<vector<ll>> testGrid = {
        {1, 1, 0, 0},
        {0, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 0, 1, 1}
    };

    ll largestIsland = maxAisland(testGrid);
    cout << "Largest island size: " << largestIsland << "\n";

    return 0;
}