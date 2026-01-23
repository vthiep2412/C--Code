#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("beads.inp", "r", stdin);
    freopen("beads.out", "w", stdout);

    string s;
    cin >> s;
    int k;
    cin >> k;

    unordered_map<char,int> mp;
    int l = 0, cnt = 0, res = INT_MAX;

    for(int r = 0; r < (int)s.size(); r++){
        mp[s[r]]++;
        if(mp[s[r]] == 1) cnt++;
        while(cnt >= k){
            res = min(res, r - l + 1);
            mp[s[l]]--;
            if(mp[s[l]] == 0){
                mp.erase(s[l]);
                cnt--;
            }
            l++;
        }
    }

    if(res == INT_MAX) cout << -1;
    else cout << res;

    return 0;
}
