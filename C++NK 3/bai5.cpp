#include <bits/stdc++.h>
using namespace std;

bool solve(int a1, int b1, int a2, int b2) {
    if ((a1 >= a2 && b1 >= b2) || (a1 >= b2 && b1 >= a2))
        {return true;}
    return false; 
}

int main() {
    int a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;

    bool result = solve(a1, b1, a2, b2);
    (result) ? cout << "YES" : cout << "NO";
    return 0;
}