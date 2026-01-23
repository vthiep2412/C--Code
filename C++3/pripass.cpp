#include <bits/stdc++.h>
using namespace std;
bool kt(int num)
{
    if (num>1)
    {
        for (int i=2; i<=sqrt(num);i++)
        {
            if (num%i==0)
            {
                return false;
            }
        }
    }
    else{return false;}
    return true;

}
int main()
{
    int n,a,b;
    cin>>n;
    for (int i = 1;i<=n;i++)
    {
        cin>>a>>b;
        cout<<"\n";
        for(int j = a;j<=b;j++)
        {
            if (kt(j))
            {
                cout<<j<<"\n";
            }
        }
        cout<<"\n";

    }
}