#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
bool found = false;
vector<int> solveClocks(const vector<int>& init)
{
    static const int moves[9][5] = {{0, 1, 3, 4, -1},{0, 1, 2, -1, -1},{1, 2, 4, 5, -1},{0, 3, 6, -1, -1},{1, 3, 4, 5, 7},{2, 5, 8, -1, -1},{3, 4, 6, 7, -1},{6, 7, 8, -1, -1},{4, 5, 7, 8, -1}};
    const int TOTAL = 262144;
    int bestSum = INT_MAX;
    int bestCnt[9] = {0};
    for (int code = 0; code < TOTAL; code++) {
        int cnt[9];
        int tmp = code;
        int sumMoves = 0;
        for (int i = 0; i < 9; i++) {
            cnt[i] = tmp % 4;
            tmp /= 4;
            sumMoves += cnt[i];
            if (sumMoves >= bestSum)
                break;
        }
        if (sumMoves >= bestSum)
            continue;
        vector<int> cur = init;
        for (int i = 0; i < 9; i++) {
            if (cnt[i] == 0)
                continue;
            for (int k = 0; k < 5; k++) {
                int id = moves[i][k];
                if (id == -1)
                    break;
                cur[id] = (cur[id] + cnt[i]) % 4;
            }
        }
        bool ok = true;
        for (int v : cur) {
            if (v != 0) {
                ok = false; break;
            }
        }
        if (ok) {
            bestSum = sumMoves;
            for (int i = 0; i < 9; i++)
                bestCnt[i] = cnt[i];
        }
    }
    if (bestSum == INT_MAX) {
        found = false;
        return {};
    }
    found = true;
    vector<int> seq;
    seq.reserve(bestSum);
    for (int i = 0; i < 9; i++)
        for (int t = 0; t < bestCnt[i]; t++)
            seq.push_back(i + 1);
    
    return seq;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    freopen("CLOCKS.INP","r",stdin);
    freopen("CLOCKS.OUT","w",stdout);
    vector<int> init(9);
    for (int i = 0; i < 9; i++)
        cin >> init[i];
    vector<int> ans = solveClocks(init);
    if (!found) {
        cout << "NO SOLUTION";
        return 0;
    }
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x << "\n";

    return 0;
}
/*
0 2 3
2 1 2
3 2 0
*/
