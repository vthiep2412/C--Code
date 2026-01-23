#include <bits/stdc++.h>
using namespace std;

bool vuong(int a, int b, int c) {
    if (a*a + b*b == c*c || a*a + c*c == b*b || b*b + c*c == a*a) {return true;}
    return false;
}

int cntsuqtria(int a) {
    int cnt = 0;
    for (int i = 1; i <= a; i++) {
        for (int j = i; j <= a; j++) {
            int c2 = i * i + j * j;
            int c = static_cast<int>(sqrt(c2));
            if (c <= a && c * c == c2) {
                if (vuong(i, j, c) && i + j + c == a) {
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
    cout.tie(0);
    int n,x;
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> x;
        cout << cntsuqtria(x) << "\n";
    }
    return 0;
}