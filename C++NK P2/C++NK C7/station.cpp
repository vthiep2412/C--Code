#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

struct e{
    ll cord,id;
};

bool comp(const e &a, const e &b) {
  return a.cord < b.cord;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("STATION.inp","r",stdin);
    freopen("STATION.out","w",stdout);
    int n, m, r;
    cin >> n >> m >> r;
    
    vector<e> stations(m);
    for (int i = 0; i < m; i++) {
    cin >> stations[i].cord;
        stations[i].id = i + 1;
    }
    sort(stations.begin(), stations.end(), comp);
    
    vector<int> ans;
    int cur = 0;
    int i = 0;
    
    while (cur<n){
        int best=-1;
        int maxr=-1;
        while(i<m and 
              stations[i].cord - r <= cur){
            if (stations[i].cord + r > maxr) {
                maxr = stations[i].cord + r;
                best = stations[i].id;
            }
            i++;
        }
        if (best == -1) {
            cout << 0 << "\n";
            return 0;
        }
    
        ans.push_back(best);
        cur = maxr + 1;
    }
    cout << ans.size() << "\n";
    for (int j = 0; j < ans.size(); j++) {
        cout << ans[j] << " ";
    }
    
    return 0;
}