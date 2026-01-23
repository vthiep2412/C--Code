#include <bits/stdc++.h>
using namespace std;


int main() {
    int a,b,c,d,cnt=0;
    double sum=0;
    cin >> a >> b >> c >> d;
    if (a % 2 == 0) {sum += a; cnt++;}
    if (b % 2 == 0) {sum += b; cnt++;}
    if (c % 2 == 0) {sum += c; cnt++;}
    if (d % 2 == 0) {sum += d; cnt++;}
    if (cnt>0) {cout << sum/cnt;}
    else {cout <<"-1";}
    return 0;
}