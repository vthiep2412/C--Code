#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("MINCOST.INP", "r", stdin);
    freopen("MINCOST.OUT", "w", stdout);

    int n; 
    cin >> n;

    long long ans = 0;
    int pre, cur;

    if (n > 0) cin >> pre;

    for (int i = 1; i < n; ++i) {
        cin >> cur;
        ans += max(pre, cur);
        pre = cur;
    }

    cout << ans << "\n";

    return 0;
}