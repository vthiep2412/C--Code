#include <bits/stdc++.h>
using namespace std;

bool kt(int num)
{
    if (num < 2);
    return false;
    for (int i=2;i<=sqrt(num);i++)
    {
        if (num%i==0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    int n,cnt=0,x;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if (a[j]>=x)
        {
            cnt++;
        }
    }
    cout<<cnt;
}