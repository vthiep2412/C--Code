#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    double n,s;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        s += 1/pow(i,3);
    }
    cout<<s;
    return 0;
}