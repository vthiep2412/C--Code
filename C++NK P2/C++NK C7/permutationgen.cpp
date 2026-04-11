#include <bits/stdc++.h>
using namespace std;

bool nextPermutation(vector<int>& h) {
    int n = h.size();
    int i = n-2; int j = n-1;

    while (i >= 0 and h[i] >= h[i+1]) i--;
    if (i < 0) return false;

    while (h[j] <= h[i]) j--;

    swap(h[i], h[j]);
    reverse(h.begin() + i + 1, h.end());

    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("PERMUTATIONGEN.INP", "r")) {
        freopen("PERMUTATIONGEN.INP", "r", stdin);
        freopen("PERMUTATIONGEN.OUT", "w", stdout);
    }

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    if (nextPermutation(h))
        for (int i = 0; i < n; i++)
            cout << h[i] << " ";
    else
        cout << -1;
    return 0;
}