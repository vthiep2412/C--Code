#include <bits/stdc++.h>
using namespace std;


bool ktnmnhuan(int so)
{
    if(so % 4==0)
    {
        if (so % 100 == 0)
        {
            if (so % 400 == 0)
            return true;
            else
            return false;
        }
        else
        {return true;}
    }
    else
    {return false;}
}

int main()
{
    int a,b;
    cin>>a;
    cin>>b;
    if (ktnmnhuan(b)==true)
    {
        if (a == 2)
        cout<<29;
        else if (a==1||a==3||a==5||a==7||a==8||a==10||a==12)
        cout<<31;
        else if (a==4||a==6||a==9||a==11)
        cout<<30;
        else
        cout<<"INVALID";
    }
    else
    {
        if (a == 2)
        cout<<28;
        else if (a==1||a==3||a==5||a==7||a==8||a==10||a==12)
        cout<<31;
        else if (a==4||a==6||a==9||a==11)
        cout<<30;
        else
        cout<<"INVALID";
    }
}