#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("CUBICS.INP", "r")) {
        freopen("CUBICS.INP", "r", stdin);
        freopen("CUBICS.OUT", "w", stdout);
    }

    ll n, k;
    if (!(cin >> n >> k)) return 0;
    map<ll, int> mp;
    mp[0] = -1; 

    ll current_sum = 0;
    int max_len = 0;
    int start_index = 0;

    for (int i = 0; i < n; i++) {
        ll val;
        cin >> val;
        current_sum += (val - k);

        if (mp.count(current_sum)) {
            int len = i - mp[current_sum];
            if (len > max_len) {
                max_len = len;
                start_index = mp[current_sum] + 1 + 1; 
            }
        } else {
            mp[current_sum] = i;
        }
    }

    if (max_len == 0) {
        cout << 0;
    } else {
        cout << max_len << " " << start_index;
    }

    return 0;
}