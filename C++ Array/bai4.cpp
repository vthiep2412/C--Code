#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s=0,s2=0,s3=0,cnt1=0,cnt2=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        s+=a[j];
        if(a[j]>0)
        {
            s2+=a[j];
            cnt1++;
        }
        if(a[j]<0)
        {
            s3+=a[j];
            cnt2++;
        }
    }
    cout<<s/n;
    cout<<s2/cnt1;
    cout<<s3/cnt2;
    return 0;
}