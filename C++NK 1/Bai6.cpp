#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int max=a,index=1;
    if (b>max) {max=b;index=2;}
    if (c>max) {max=c;index=3;}
    if (d>max) {max=d;index=4;}
    cout << index;
    return 0;
}