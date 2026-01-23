#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("FLAG.inp", "r", stdin);
    freopen("FLAG.out", "w", stdout);
    
    umap<char, int> firstcol, secondcol, thirdcol;
    vector<string> flag(6);
    for(auto& s: flag) cin >> s;
    for(auto& s: flag) {
        for(int j = 1; j <= 3 ;j++) firstcol[s[j-1]]++;
        for(int j = 4; j <= 6 ;j++) secondcol[s[j-1]]++;
        for(int j = 7; j <= 9;j++) thirdcol[s[j-1]]++;
    }
    
    char col1, col2, col3;
    
    col1 = max_element(all(firstcol), [](auto a, auto b){return a.second < b.second;}) -> first;
    col2 = max_element(all(secondcol), [](auto a, auto b){return a.second < b.second;}) -> first;
    col3 = max_element(all(thirdcol), [](auto a, auto b){return a.second < b.second;}) -> first;

    int cnt=0;
    for(auto x: flag){
        for(int j = 1; j<=3;j++) if(x[j-1] != col1) cnt++;
        for(int j = 4; j<=6;j++) if(x[j-1] != col2) cnt++;
        for(int j = 7; j<=9;j++) if(x[j-1] != col3) cnt++;
    }
    cout << cnt;
    return 0;
}