#include <bits/stdc++.h>
using namespace std;

const int MAX_max = 100000;
vector<int> sodep;

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

int sumofnum(int x) {
    int t = 0;
    while (x != 0) t += (x % 10) * (x % 10), x /= 10;
    return t;
}

void sangsodep() {
    for (int i = 2; i <= MAX_max; i++) {
        if (kt(sumofnum(i))){
            sodep.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("beauty.inp", "r", stdin);
    freopen("beauty.out", "w", stdout);
    sangsodep();
    int n;
    while(cin >> n) {   
        cout<<sodep[n-1]<<"\n";
    }
    return 0;
}