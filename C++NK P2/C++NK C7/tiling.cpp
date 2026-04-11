#include <bits/stdc++.h>
using namespace std;

int main() {
  if (fopen("TILING.INP", "r")) {
    freopen("TILING.INP", "r", stdin);
    freopen("TILING.OUT", "w", stdout);
  }

  long long ways[55];
  ways[0] = 1;
  ways[1] = 1;

  for (int i = 2; i <= 50; i++) {
    ways[i] = ways[i - 1] + 2 * ways[i - 2];
  }

  int n;
  while (cin >> n) {
    cout << ways[n] << "\n";
  }

  return 0;
}