#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("crobot.inp", "r", stdin);
    freopen("crobot.out", "w", stdout);
    int n, t = 1,x=0,y=0;
    string s;
    cin>>n>>s;
    for(char c : s){
        if(c=='L') t = (t+3)%4;
        else if(c=='R') t = (t+1)%4;
        else if(c=='B') t = (t+2)%4;
        x += dx[t]; y += dy[t];
    }
    cout<<x<<" "<<y;
    return 0;
}