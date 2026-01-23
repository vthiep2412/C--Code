#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,cnt=0,sum=0,sum_max=INT_MIN;
    n=10;
    int a[10]={1,-2,-3,4,-5,-6,1,-6,-7,9};
    // for (int i=0;i<n;i++)
    // {
    //     cin>>a[i];
    // }
    for (int i=0;i<=n;i++)
    {
        if (i<n&&a[i]<0)
        {
            sum+=a[i];
        }
        else
        {
            if(sum<0){
                if(sum>sum_max)
                {
                    sum_max=sum;
                    cnt=1;
                }
                else if (sum==sum_max){
                    cnt++;
                }
                sum=0;
            }
        }
    }
    cout<<sum_max<<" "<<cnt;
    return 0;
}