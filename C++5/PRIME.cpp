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
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("PRIME.inp", "r", stdin);
    // freopen("PRIME.out", "w", stdout);
    string n;
    cin >> n;
    int s=0;
    for(int i=0;i<n.size();i++){
        if(isdigit(n[i])){
            if(kt(n[i]-'0')){
                s+=n[i]-'0';
            }
        } 
    }
    cout<<s;
}