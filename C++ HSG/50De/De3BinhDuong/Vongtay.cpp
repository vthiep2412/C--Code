#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("Vongtay.inp", "r", stdin);
    //freopen("Vongtay.out", "w", stdout);
    int x;
    char q;
    string s;
    cin>>x;
    while(x--){
        cin>>q;
        s.push_back(q);
    }
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if ((n - 1) % i == 0) {
            string pattern = s.substr(0, i);
            bool ok = true;
            for (int j = 0; j <= n - 1 - i; j += i) {
                if (s.substr(j, i) != pattern) {
                    ok = false;
                    break;
                }
            }
            // Kiểm tra hạt cuối cùng (phải giống hạt đầu tiên của pattern)
            if (ok && s[n - 1] == pattern[0]) {
                cout << i << "\n";
                return 0;
            }
        }
    }
    return 0;
}