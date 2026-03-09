#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("STRGAME.inp", "r", stdin);
    //freopen("STRGAME.out", "w", stdout);
    string s;
    int n, k;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    vector<string> groups(k);
    for(int i = 0; i < n; i++)
        groups[i % k] += s[i];
    string rrMax = *max_element(groups.begin(), groups.end());
    string simpleMax = s.substr(k - 1);

    cout << min(rrMax, simpleMax);
    return 0;
}