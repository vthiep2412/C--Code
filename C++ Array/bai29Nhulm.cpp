#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n=9,cnt=0,dm=0,d=0;
    // cin>>n;
    vector<int> a={2,3,4,4,3,7,9,8,8};
    // for(int i=0;i<n;i++)
    // {
    //     cout<<"Nhap phan tu:";
    //     cin>>a[i];
    // }
    cout<<"Doan con:"<<endl;
    for(int j=0;j<=n;j++)
    {
        if(j<n&&a[j]>=a[j+1])
        {
            d++;
        }
        else
        {
            if(d>0)
            {
                if(d>dm)
                {
                    dm=d;
                    cnt=1;
                }
                d=0;
                cnt=0;
            }
        }
    }
    for(int j=0;j<=n;j++)
    {
        if(j<n&&a[j]>=a[j+1])
        {
            d++;
        }
        else
        {
            if(d==dm)
            {
                for(int i=j-d;i<j;i++)
                    cout<<a[i]<<" ";
                cout<<endl;
                cnt++;
            }
            d=0;
        }
    }
    cout<<"Do dai lon nhat:"<<dm<<endl;
    cout<<"So doan con:"<<cnt;

    return 0;
}
