#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k,v,cnt=0;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++)
    {
        cin>>v;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == v)
            {
                cnt++;
            }
        }
        if (cnt>0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        v=0;
        cnt=0;
    }
}