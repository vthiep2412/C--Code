#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b,c,d;
    int mul=1;
    cin >> a >> b >> c >> d;
    if (a!=0) mul*=a;
    if (b!=0) mul*=b;
    if (c!=0) mul*=c;
    if (d!=0) mul*=d;
    cout << mul;
    return 0;
}