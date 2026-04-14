#include<bits/stdc++.h>
using namespace std;

struct Node {
    int l, r;
    bool operator<(const Node &other) const {
        if (r == other.r) return l > other.l;
        return r < other.r;
    }
};

int n;
vector<Node> a;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("REP.INP", "r", stdin);
    freopen("REP.OUT", "w", stdout);

    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r;
    }

    sort(a.begin(), a.end());
    for (Node &x : a) {
        int cnt = 0;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (v[i] < x.l) break;
            cnt++;
            if (cnt >= 2) break;
        }
        if (cnt == 0) {
            v.push_back(x.r - 1);
            v.push_back(x.r);
        } else if (cnt == 1) {
            if (v.back() == x.r) {
                int last = v.back();
                v.pop_back();
                v.push_back(x.r - 1);
                v.push_back(last);
            } else {
                v.push_back(x.r);
            }
        }
    }

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
}