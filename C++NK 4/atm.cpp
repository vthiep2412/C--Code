#include <iostream>
using namespace std;

int AtmDem(int a, int b, int c, int n) {
    int cnt = 0;

    for (int x=0; x<=c && x*20 <= n; x++) {
        for (int y=0; y<=b && (x*20+y*10) <= n; y++) { 
            int conlai = n-(x*20+y*10);
            if (conlai%5 == 0) {
                int z=conlai/5;
                if (z<=a) {
                    cnt++;
                }
            }
        }
    }
    
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("atm.INP", "r", stdin);
    freopen("atm.OUT", "w", stdout);
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << AtmDem(a, b, c, n);
    return 0;
}
