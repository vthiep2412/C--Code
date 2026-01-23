#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n) {
    string binary;
    while (n > 0) {
        binary = (n % 2 == 0 ? "0" : "1") + binary;
        n /= 2;
    }
    return binary.empty() ? "0" : binary;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    long long n;
    long long cnt=0,sum=0;
    cin>>n;
    string s = decimalToBinary(n);
    while (n!=0){
        cnt++;
        n/=10;
    }
    for(char c:s){
        sum+=(c-'0');
    }
    if(sum%cnt==0){
        cout<<"CO";
    }
    else{
        cout<<"KHONG"; 
    }
    return 0;
}