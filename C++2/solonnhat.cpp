#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long a,b,c;
    int max;
    cin>>a;
    cin>>b;
    cin>>c;
    max = a;
    if(max < b)
    max= b;
    if(max<c)
    max=c;
    cout<<max;

    return 0;
}