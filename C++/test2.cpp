#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> a(n),b;
    const int c=a.size();
    if(n>=40)
    {
        return 0;
    }
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }
    for(int i=0;i<c;i++)
    {
        if(a[i]==a[i+1]&&a[i]>=k)
        {
            if(find(b.begin(),b.end(),a[i])!=b.end())
            {}
            else{b.push_back(a[i]);}
        }
    }
    for(int i=0;i<b.size();i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}