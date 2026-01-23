#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("CLIS.INP", "r", stdin);
    freopen("CLIS.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> b(n);
    for (int &x : b) cin >> x;
    b.insert(b.end(), b.begin(), b.end());

    int max_len = 0;
    int l = 0;
    pair<int, int> res;
    for (int r = 1; r < 2 * n; ++r) {
        if (b[r] < b[r - 1]) l = r;
        if (r - l + 1 > max_len && r - l + 1 <= n) {
            max_len = r - l + 1;
            res={l, r};
        }
    }
    int p = (res.first % n) + 1;
    int q = (res.second % n) + 1;
    cout << p << " " << q << endl;
    return 0;
}