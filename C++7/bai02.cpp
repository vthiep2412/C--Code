#include <bits/stdc++.h>
using namespace std;

void solve(long long n) {
    long long s = 1, a = 1, b = 1, i = 3;
    while (i <= n) {
        s = a + b;
        a = b;
        b = s;
        cout<<s<<" ";
        i++;
    }
}

int main() {
    long long n;
    cin >> n;
    cout<<"1 1 2 ";
    solve(n);
    return 0;
}