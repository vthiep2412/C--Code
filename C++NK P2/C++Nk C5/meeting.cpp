#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int s, f, id;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MEETING.INP", "r", stdin);
    freopen("MEETING.OUT", "w", stdout);

    int n;
    cin >> n;
    vector<Meeting> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s >> a[i].f;
        a[i].id = i + 1;
    }

    // sort by finish time
    sort(a.begin(), a.end(), [](Meeting &x, Meeting &y) {
        if (x.f == y.f) return x.s < y.s;
        return x.f < y.f;
    });

    vector<int> ans;
    int lastEnd = -1;
    for (auto &m : a) {
        if (m.s >= lastEnd) {
            ans.push_back(m.id);
            lastEnd = m.f;
        }
    }

    cout << ans.size() << "\n";
    for (int id : ans) cout << id << "\n";

    return 0;
}
