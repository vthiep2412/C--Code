#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b,c,d,min;
    cin >> a >> b >> c >> d;
    min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    if (d < min) min = d;
    cout << min;
    return 0;
}