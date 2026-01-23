#include <bits/stdc++.h>
using namespace std;

int solve(int a, int n) {
    int i=0;
    while(a<n){
        a*=2;
        i++;
    }
    return i;
}

int main() {
    int a, n;
    cin >> a >> n;
    int x=solve(a,n);
    cout<<x;
    return 0;
}

