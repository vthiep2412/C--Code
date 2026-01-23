#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    int c=sqrt(n);
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= c; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve(int n) {
    int cnt = 1;
    for (int i = 2; cnt <= n; i++) {
        if (isPrime(i)) {
            cout << i << endl;
            cnt++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    if(n<0) return 0;
    if(n==1){cout<<2;}
    else{solve(n);}
    return 0;
}

