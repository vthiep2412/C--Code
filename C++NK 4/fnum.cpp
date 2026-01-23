#include <iostream>
#include <cmath>
using namespace std;

int sumofuoc(int n) {
    if(n < 2) return 0;
    int sum = 0;
    int lim = sqrt(n);
    for (int i = 2; i <= lim; i++) {
        if(n % i == 0) {
            sum += i;
            int d = n / i;
            if(d != i)
                sum += d;
        }
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("FNUM.INP", "r", stdin);
    freopen("FNUM.OUT", "w", stdout);
    int n,cnt=0;
    cin >> n;
    for(int i = 48; i <= n; i++){
        int s = sumofuoc(i);
        if(s > i && s <= n && sumofuoc(s) == i){
            cout << i << " " << s << "\n";
            cnt++;
        }
    }
    if(cnt == 0) cout << -1;
    return 0;
}