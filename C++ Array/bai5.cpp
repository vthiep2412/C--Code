#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if(a[j]>0)
        {
            cout<<j;
            break;
        }
    }
    return 0;
}