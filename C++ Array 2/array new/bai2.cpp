#include <bits/stdc++.h>
using namespace std;

bool kt(int n) {
    if (n <= 1) {return false;}
    int s = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            s += i;
        }
    }
    return (s == n);
}

int main() {
    int n,s=0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < a.size(); i++)
    {
        if(kt(a[i]))
        {
            s+=a[i];
        }
    }
    cout << s;
    return 0;
}
