#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,max=0,index=0,max2=0,index2=0,luumax=0,luuindex=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if (a[j]>max)
        {
            max2=max;
            index2=index;
            max=a[j];
            index=j;
        }
        else if (max>=a[j]&&a[j]>=max2)
        {
            max2=a[j];
            index2=j;
        }
    }
    cout<<max2<<" "<<index2;
    return 0;   
}