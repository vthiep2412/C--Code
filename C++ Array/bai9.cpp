#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,max=0,index=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if(a[j]>max)
        {
            max=a[j];
            index=j;
        }
    }
    cout<<index<<" "<<max;
    return 0;
}