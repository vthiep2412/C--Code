#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    int s=1,i;
    if (n%2==0){
        i=2;
    }
    else {
        i=1;
    }
    while (i<=n) {
        s*=i;
        i+=2;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    int ketqua = solve(n);
    cout << ketqua;
    return 0;
}