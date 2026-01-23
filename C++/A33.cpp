#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int n,x,d;
    cin>>n;
    for (int i=0;i<=n/2;i++)
    {
        x=n-i;
        if (x>=i)
        {
            d = d+1;
        }
    }
    cout<<d;
}