#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n,a=0;
    bool b = true;
    cin>>n;
    if(n>1){
    for (int i = 2; i < sqrt(n); i++) {
        if (n % i == 0) {
            b = false;
            }
        }
    }
    if (b==true)
    {
        cout<<n<<" la so nguyen to";
    }
    return 0;
}