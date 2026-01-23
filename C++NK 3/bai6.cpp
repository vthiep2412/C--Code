#include <bits/stdc++.h>
using namespace std;

int solve(int r1, int c1, int r2, int c2) {
    double s1 = 3.141*r1*r1,s2=3.141*r2*r2;
    double val1 = s1/c1, val2 = s2/c2;
    if (val1 > val2)
        return 1 ;
    return 2;
}

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int result = solve(r1, c1, r2, c2);
    cout<<result;
    return 0;
}

    