#include <bits/stdc++.h>
using namespace std;

map<int, int> X, Y;
multiset<int> xLen, yLen;

void cut(int cutPos, map<int, int> &m, multiset<int> &s) {
    auto i = m.upper_bound(cutPos);
    if (i == m.begin()) return;
    --i;
    
    int start = (*i).first, len = (*i).second, e = start + len;
    
    if (cutPos > start && cutPos < e) {
        s.erase(s.find(len));
        (*i).second = cutPos - start;
        m[cutPos] = e - cutPos;
        s.insert(cutPos - start);
        s.insert(e - cutPos);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	freopen("MAXPIECE.inp","r",stdin);
    freopen("MAXPIECE.out","w",stdout);
    int n, m, k, t, v;
    if (!(cin >> n >> m >> k)) return 0;
    
    X[0] = n; Y[0] = m;
    xLen.insert(n); yLen.insert(m);
    
    while (k--) {
        cin >> t >> v;
        t ? cut(v, Y, yLen) : cut(v, X, xLen);
    }
    
    int xMax = *xLen.rbegin(), yMax = *yLen.rbegin();
    cout << (xMax < yMax ? xMax : yMax) << endl;
    
    return 0;
}