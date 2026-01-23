#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int N,s;
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        s += i;
    }
    cout<<s;
    return 0;
}