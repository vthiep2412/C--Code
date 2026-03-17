#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("GIFTS.INP", "r", stdin);
    freopen("GIFTS.OUT", "w", stdout);

    vector<long long> a;
    long long x;
    while (cin >> x) a.push_back(x);

    int n = a.size();
    unordered_set<long long> s(a.begin(), a.end());
    unordered_set<long long> gift;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long sum = a[i] + a[j];
            if (sum % 2 == 0) {
                long long avg = sum / 2;
                if (s.count(avg)) gift.insert(avg);
            }
        }
    }

    cout << gift.size() << "\n";
    return 0;
}
