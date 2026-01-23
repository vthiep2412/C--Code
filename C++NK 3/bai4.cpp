#include <bits/stdc++.h>
using namespace std;

bool solve(int a, int b, int r) {
    int d = 2*r;
    if (a >= d && b >= d)
        return true;
    return false; 
}

int main() {
    int a, b, r;
    cin >> a >> b >> r;

    bool result = solve(a, b, r);
    (result) ? cout << "YES" : cout << "NO";
    return 0;
}

