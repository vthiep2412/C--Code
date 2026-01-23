#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b,c,d,sum=0;
    cin >> a >> b >> c >> d;
    if (a%2!=0) sum+=a;
    if (b%2==0) sum+=b;
    if (c%2==0) sum+=c;
    if (d%2==0) sum+=d;
    cout << sum;
    return 0;
}