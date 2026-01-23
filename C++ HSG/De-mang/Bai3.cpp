#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int i = 1, cnt = 0;
    int m = sqrt(n);
    while (i <= m) {
        if (n % i == 0) {
            cnt += 2;
        }
        i++;
    }
    if (n == m*m) {
        cnt--;
    }
    return cnt;
}

int main() {
   int n,m,cnt=0;
   cin >> n >> m;
   for(int i = n; i <= m; i++){
       if(solve(i) == 3) cnt++; 
   } 
   cout << cnt;
}