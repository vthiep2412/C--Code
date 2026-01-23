#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int N, k,s;
    cout<< "Nhập số nguyên dương: ";
    cin>>N;
    cout<< "Nhập số nguyên dương thứ 2: ";
    cin>>k;
    for (int i=1;i<=N;i++)
    {
        if(i%k==0)
        {
            s+=1;
        }
    }
    cout<<s;
    return 0;
}