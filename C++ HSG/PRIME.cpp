#include <bits/stdc++.h>
using namespace std;

bool kt(long long n){
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    const long long c2 = sqrt(n);
    for (long long i = 5; i <= c2; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("PRIME.inp", "r", stdin);
    freopen("PRIME.out", "w", stdout);
    int s,sum=0,c;
    string n,b;
    cin>>n;
    for (char c : n) {
        if (isdigit(c)) {
            b += c;
        }
    }
    c = stoi(b);
    while(c > 0)
    {
        s=c%10;
        if (kt(s)==true)
        {
            sum+=s;
        }
        c/=10;
    }
    cout<<sum;

    return 0;
}