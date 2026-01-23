#include <iostream>
#include <math.h>
using namespace std;

bool kt(int num)
{
    bool b = true;
    if(num>1){
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                b=false;    
                }
            }
    }
    else {b=false;}
    return b;
}
bool kts(int n)
{
    int b=n;
    bool c=true;
    if (kt(n)==true)
    {
        while(n>0)
        {
            if (kt(n)==false)
            {c=false;}
            n=n/10;
        }
    }
    else{c=false;}
    return c;
}


int main()
{
    int input,input2;
    cin>>input;
    cin>>input2;
    for (int i = input; i<=input2;i++)
    {
        if(kts(i)==true)
        {cout<<i<<" ";}
    }

    return 0;
}