#include <bits/stdc++.h>
using namespace std;

int main() {
    int s,max=0,a=0;
    double n;
    cin >> n;
    s=trunc(n);
    while(s>0)
    {
        a=s%10;
        if(max<a)
            max=a;
        s/=10;
    }
    cout<<max;
    return 0;
}