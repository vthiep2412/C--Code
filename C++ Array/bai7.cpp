#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,s=0,c;
    cin>>n;
    c=n-1;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=c;j>=0;j--)
    {
        if(a[j]>0)
        {
            cout<<j;
            break;
        }
    }
    return 0;
}