#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s=0,prevcnt=0,cnt=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=0;j<n;j++)
    {
        if (a[j]>0 && a[j+1]<0 || a[j]<0 && a[j+1]>0)
        {
            cnt++;
        }
        else {
            if(prevcnt<cnt)
            {
                prevcnt=cnt;
                cnt=0;
            }
        }
    }
    cout<<prevcnt+1;
}