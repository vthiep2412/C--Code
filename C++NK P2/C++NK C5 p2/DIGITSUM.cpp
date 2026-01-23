#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()

string vectorTOstring(vector<string>& a){
    string s = "";
    for(auto& x: a) s += x;
    return s;
}

ll toll(string s){
    stringstream ss(s);
    ll x;
    ss >> x;
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("DIGITSUM.inp", "r", stdin);
    // freopen("DIGITSUM.out", "w", stdout);

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        vector<string> a(x);
        vector<string> f,g;
        for(auto& s: a) cin >> s;
        sort(all(a));
        int mid = a.size() / 2;
        if(x % 2 == 0) mid--;
        for(int j = 0; j < mid; j++){
            f.push_back(a[j]);
            a[j] = "";
        }
        f.push_back(a.back());
        a.back() = "";
        for(int j = mid; j < a.size(); j++) {
            if(a[j].empty()) continue;
            g.push_back(a[j]);
            a[j] = "";
        }
        string s1 = vectorTOstring(f);
        string s2 = vectorTOstring(g);
        cout << toll(s1) + toll(s2) << "\n";
    }

    return 0;
}