#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    unordered_set<int> a;
    for (int i = 0; i < n; i++) {
        int nhap;
        cin >> nhap;
        a.insert(nhap);
    }
    for (int i = 1; i <= sqrt(INT_MAX); i++) {
        int sq = i * i;
        if (a.find(sq) == a.end()) {
            cout << sq;
            return 0;
        }
    }
    return 0;
}