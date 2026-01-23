#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("DIGIT.inp", "r", stdin);
    freopen("DIGIT.out", "w", stdout);
    string s,ans="";
    cin>>s;
    int k;
    cin>>k;
    for (char c : s) {
        while (k > 0 and !ans.empty() and ans.back() < c) {
            ans.pop_back();
            k--;
        }
        ans.push_back(c);
    }
    while (k--) ans.pop_back();
    cout<<ans;
    return 0;
}