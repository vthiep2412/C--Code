#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    long long a,b,cnt=0;
    cin>>a>>b;
    while(a!=0 and b!=0){
        if(a<b) swap(a,b);
        long long temp = abs(a-b);
        a=b;
        b=temp;
        cnt++;
    }
    cout<<cnt;
    return 0;
}