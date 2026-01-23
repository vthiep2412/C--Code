#include <bits/stdc++.h>
using namespace std;

bool kt(int n)
{
    if (n<2)
    {
        return false;
    }
    for (int i=2;i<=sqrt(n);i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n,s=0;
    cin >> n;
    vector<int> a(n);
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<n;i++)
    {
        if (kt(a[i]))
        {
            s+=a[i];
        }
    }
    cout << s;
    return 0;
}

