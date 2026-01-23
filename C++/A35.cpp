#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int A, B, s;
    cout<< "Nhập số nguyên dương A: ";
    cin>>A;
    cout<< "Nhập số nguyên dương B: ";
    cin>>B;
    for (int i=A;i<=B;i++)
    {
        if(i%2==0)
        {
            s+=1;
        }
    }
    cout<<s;
    return 0;
}