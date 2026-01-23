#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c,d,sum=0,cnt=0,tbc;
    cin>>a>>b>>c>>d;
    if (a%2==0)
        {
            sum += a;
            cnt+=1;
        }
    if (b%2==0)
        {
            sum += b;
            cnt+=1;
        }
    if (c%2==0)
        {
            sum += c;
            cnt+=1;
        }
    if (d%2==0)
        {
            sum += d;
            cnt+=1;
        }
    if (cnt>0)
        {
            tbc = sum/cnt;
            cout<<tbc;
        }
    else
        {
            cout<<-1;
        }
    return 0;
}