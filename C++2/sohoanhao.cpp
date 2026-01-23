#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b,sum,hoanhao;
    cin>>n;
    if(n>0)
        for (int i = 1; i <= n; i++)
        {
            if (n%i==0)
            {
                sum+=i;
            }
        }
        hoanhao = sum - n;
        if (hoanhao == n)
            {
                cout<<"YES";
            }
        else
            {
                cout<<"NO";
            }
}