#include <bits/stdc++.h>
using namespace std;

int main() {
    int i=2,j=1,t=1,n=3;
    while(t<=n){
        j=i*t;
        t=t+j;
        i++;
    }
    cout<<j<<endl;
    return 0;
}
