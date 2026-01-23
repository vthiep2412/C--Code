#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n;
    while (n>0)
    {
        a=n%10;
        b=b*10+a;
        n/=10;

    }
    cout<<b;
    return 0;
}