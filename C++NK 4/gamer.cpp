#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("GAMER.inp", "r", stdin);
    freopen("GAMER.out", "w", stdout);
    
    int n,s=0;
    cin>>n;
    for(int i = 0; i <= n/2; i++)
    {
        s+=i;
        if(s>=n)
        {
            cout<<i;
            break;
        }   
    }
    return 0;
}

