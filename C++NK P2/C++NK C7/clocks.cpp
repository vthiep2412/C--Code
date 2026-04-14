#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  freopen("CLOCKS.INP", "r", stdin);
  freopen("CLOCKS.OUT", "w", stdout);

  int s[9];
  for (int i = 0; i < 9; ++i) cin >> s[i];

  int minSteps = 40;
  int res[10];
  bool found = false;

  for (int x1 = 0; x1 < 4; ++x1) {
    if (x1 >= minSteps) break;
    for (int x2 = 0; x2 < 4; ++x2) { 
      if (x1 + x2 >= minSteps) break;
      for (int x3 = 0; x3 < 4; ++x3) {
        if (x1 + x2 + x3 >= minSteps) break; 
        for (int x4 = 0; x4 < 4; ++x4) { 
          if (x1 + x2 + x3 + x4 >= minSteps) break; 
          for (int x5 = 0; x5 < 4; ++x5) { 
            if (x1 + x2 + x3 + x4 + x5 >= minSteps) break; 
            for (int x6 = 0; x6 < 4; ++x6) {
              if (x1 + x2 + x3 + x4 + x5 + x6>= minSteps) break; 
              for (int x7 = 0; x7 < 4; ++x7) {
                if (x1 + x2 + x3 + x4 + x5 + x6 + x7>= minSteps) break; 
                for (int x8 = 0; x8 < 4; ++x8) { 
                  if (x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8>= minSteps) break; 
                  for (int x9 = 0; x9 < 4; ++x9) {
                    int total = x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9;
                    if (total >= minSteps) break;

                    if ((s[0] + x1 + x2 + x4) % 4 == 0 and
                        (s[1] + x1 + x2 + x3 + x5) % 4 == 0 and
                        (s[2] + x2 + x3 + x6) % 4 == 0 and
                        (s[3] + x1 + x4 + x5 + x7) % 4 == 0 and
                        (s[4] + x1 + x3 + x5 + x7 + x9) % 4 == 0 and
                        (s[5] + x3 + x5 + x6 + x9) % 4 == 0 and
                        (s[6] + x4 + x7 + x8) % 4 == 0 and
                        (s[7] + x5 + x7 + x8 + x9) % 4 == 0 and
                        (s[8] + x6 + x8 + x9) % 4 == 0) {
                      minSteps = total;
                      res[1] = x1; res[2] = x2; res[3] = x3;
                      res[4] = x4; res[5] = x5; res[6] = x6;
                      res[7] = x7; res[8] = x8; res[9] = x9;
                      found = true;
                    }}}}}}}}}}
  if (!found) {
    cout << "NO SOLUTION\n"; return 0;
  }
  cout << minSteps << "\n";
  for (int i = 1; i <= 9; ++i)
    while (res[i]--) cout << i << "\n";
  return 0;
}