#include <bits/stdc++.h>
using namespace std;

vector<int> best(82,-1);
vector<string> bestS(82);
int bestD=100;
pair<int,int> bestAns;
int bestI = 2e9, bestJ = 2e9;

int digSum(const string &x){
    int sum=0;
    for(const char &c:x)
        sum += (c-'0');
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("Password.inp", "r", stdin);
    freopen("Password.out", "w", stdout);
    int n; string x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        int sum = digSum(x);
        if(best[sum] == -1){
            best[sum] = i;
            bestS[sum] = x;
        }
    }
    for (int s1 = 1; s1 <= 81; s1++) {
        if (best[s1] == -1) continue;
        for (int s2 = s1 + 1; s2 <= 81; s2++) {
            if (best[s2] == -1) continue;
            int d = abs(s1 - s2);
            
            int curI = min(best[s1],best[s2]);
            int curJ = max(best[s1],best[s2]);
            
            if (d<bestD){
                bestD = d;
                bestI = curI, bestJ = curJ;
                if (best[s1] < best[s2]) bestAns = {s1, s2};
                else bestAns = {s2, s1};
            } else if(d==bestD){
                if(curI < bestI or 
                  (curI == bestI and curJ < bestJ)){
                    bestI = curI, bestJ = curJ;
                    if (best[s1] < best[s2]) bestAns = {s1, s2};
                    else bestAns = {s2, s1};
                }
                
            }
        }
    }
    cout<<bestS[bestAns.first]<<bestS[bestAns.second];
    return 0;
}