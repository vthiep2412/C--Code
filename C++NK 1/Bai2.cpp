#include <bits/stdc++.h>
using namespace std;


int main() {
    int cnt=0,a,b,c,d;
    cin >> a >> b >> c >> d;
    if (a>0) cnt++;
    if (b>0) cnt++;
    if (c>0) cnt++;
    if (d>0) cnt++;
    cout << cnt;
    return 0;
}