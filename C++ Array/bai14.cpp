#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,min=0,index=0,prevmin=0,previndex=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if(a[j]>min)
        {
            prevmin=min;
            previndex=index;
            min=a[j];
            index=j;
        }
    }
    cout<<previndex<<" "<<prevmin;
    return 0;   
}