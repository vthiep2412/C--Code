#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x;
    vector<int> a(n);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;
    a.erase(a.begin() + x - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
}