#include <bits/stdc++.h>
using namespace std;

void solve(int a, int b, int c) {
    int y;
    for (int x = 0 ; x <= c/a; x++) {
        y = (c-a*x)/b;
        if (a * x + b * y == c) {
            cout<<x<<" "<<y<<"\n";
        }
    }
}

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    solve(a,b,c);
    return 0;
}

