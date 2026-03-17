#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct e {
    string no, wz;
};

bool isLT(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

bool isLE(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a <= b;
}

e findzero(const string &s, ll i, string tgt, string tgt2) {
    string r, r2;
	if(s[i]==0)tgt = tgt2;
    ll sz = s.size();
    bool f = 0, z = 0;
    while (i < sz && s[i] != '0') {
        if (!f) {
            r += s[i];
            if (isLT(tgt, r)) f = 1;
        }
        r2 += s[i];
        i++;
    }
    while (i < sz && s[i] == '0') {
        z = 1;
        if (!f) {
            r += s[i];
            if (isLT(tgt, r)) f = 1;
        }
        r2 += s[i];
        i++;
    }
    if (!z || i == sz) return {r, r};
    return {r, r2};
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen(".INP", "r")) {
        freopen(".INP", "r", stdin);
        freopen(".OUT", "w", stdout);
    }

    string s;
    cin >> s;
    vector<e> a;

    for (ll i = 0; i < s.size(); i++) {
        if (a.empty()) {
            string t = s.substr(i, 1);
            a.push_back({t, t});
            continue;
        }

        e x = findzero(s, i, a.back().wz);
        
        if (isLT(a.back().wz, x.no)) {
            a.push_back(x);
            i += x.wz.size() - 1;
        } else if (isLT(a.back().wz, x.wz)) {
            a.push_back({x.wz, x.wz});
            i += x.wz.size() - 1;
        } else {
            break;
        }
    }
	cout<<a.size()<<"\n";
    for (ll i = 0; i < a.size(); i++) {
        if (i + 1 < a.size()) cout << a[i].wz << " ";
        else cout << a[i].no;
    }
    return 0;
}