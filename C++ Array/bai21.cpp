#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,s=0,b,cnt=0,prevcnt=0;
    cin>>n;
    int a[n];
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    for (int j=1;j<n;j++)
    {
        b=a[j-1];
        if(a[j]<b)
        {
            cnt++;
        }
        else {
            if(prevcnt<cnt)
            {
                prevcnt=cnt;
            }
            cnt = 0;
        }
    }
    if(prevcnt < cnt) {
        prevcnt = cnt;
    }
    if(prevcnt > 0) {
        prevcnt += 1;
    }
    cout<<prevcnt;
    return 0;
}