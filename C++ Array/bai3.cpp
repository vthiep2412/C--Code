#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[1000],n,cnt=0,s=0;
    cin>>n;
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int i=0;i<n;i++)
    {
        if(a[i]<0)
        {
            s+=a[i];
            cnt++;
        }
    }
    cout<<s<<" "<<cnt;
}