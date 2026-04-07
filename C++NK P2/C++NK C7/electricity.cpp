#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  if (fopen("ELECTRICITY.INP", "r")) {
    freopen("ELECTRICITY.INP", "r", stdin);
    freopen("ELECTRICITY.OUT", "w", stdout);
  }

  int n, k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int ans = 0;
  int cur = 0;

  while (cur < n) {
    int bestP = -1;
    int r = min(n - 1, cur + k - 1);
    int l = max(0, cur - k + 1);

    for (int i = r; i >= l; i--) {
      if (a[i] == 1) {
        bestP = i;
        break;
      }
    }

    if (bestP == -1) {
      cout << -1 << "\n";
      return 0;
    }

    ans++;
    cur = bestP + k;
  }

  cout << ans << "\n";

  return 0;
}