#include <bits/stdc++.h>
using namespace std;

int UCLN(long a,long b){
    return __gcd(a,b);
}

int UCLNcu(long a,long b){
    long min = std::min(a,b);
    for(int i = min; i >= 1; i--){
        if ( a % i == 0 && b % i == 0){
            return i;
        }
    }
    return 0;
}

int UCLNmoi(long a,long b){
    while(b>0){
        a = a%b;
        int tmp=a;
        a=b;
        b=tmp;
    }
    return a;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("ucln.inp","r",stdin);
    freopen("ucln.out","w",stdout);
    long long a,b;
    cin>>a>>b;
    cout<<__gcd(a,b);
    return 0;
}