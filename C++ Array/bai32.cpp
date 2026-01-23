#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,cnt=0,x;
    cin>>n;
    int a[n];
    cin>>x;
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if (a[j]!=x)
        {
            cnt++;
        }
    }
    cout<<cnt;
}