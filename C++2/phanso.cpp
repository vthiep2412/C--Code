#include <bits/stdc++.h>
using namespace std;
int uc(int a,int b)
{
    for (int i = min(a,b); i > 0; i--)
        if (a%i==0 && b%i==0)
            return i;
    return 1;
}

int main()
{
    int x,y,c;
    bool f=false;
    cin>>x>>y;
    if(x<0||y<0)
        {x=abs(x);y=abs(y);f=true;}
    c = uc(x,y);
    if (f==true)
        cout<<"-"<<x/c<<" "<<y/c<<endl;
    else
        cout<<x/c<<" "<<y/c<<endl;

}