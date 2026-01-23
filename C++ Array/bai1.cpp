#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[1000],n,s=0;
    cin>>n;
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        s+=a[j];
    }
    cout<<s;
}