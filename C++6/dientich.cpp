#include <bits/stdc++.h>
using namespace std;
double pi = 3.14;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    // freopen("dientich.inp", "r", stdin);
    // freopen("dientich.out", "w", stdout);
    double a,b;
    cin >> a >> b;
    double r = a/2;
    double s = pi*r*r;
    double s2 = (a*b)-s;
    cout << s2;
    return 0;
}