#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (i != j && i != k && a[i] == a[j] + a[k])
                {
                    cout << a[i] << " = " << a[j] << " + " << a[k] << endl;
                }
            }
        }
    }
    return 0;
} 