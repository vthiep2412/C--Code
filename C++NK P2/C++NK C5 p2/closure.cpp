#include <bits/stdc++.h>
using namespace std;
const int maxValue = 100001;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    freopen("CLOSURE.inp", "r", stdin);
    freopen("CLOSURE.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> firstPos(maxValue, -1);
    int maxLen = 0;

    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;

        if (firstPos[value] != -1) {
            int currentLen = i - firstPos[value] + 1;
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        } else {
            firstPos[value] = i;
        }
    }

    cout << maxLen;

    return 0;
}