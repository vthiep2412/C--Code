#include <bits/stdc++.h>
using namespace std;

bool kt(int n){
    int a = sqrt(n);
    if(a*a==n)
    {
        return true;
    }
    return false;
}

int main() {
    int n,cnt=0;
    vector<int> a(n);
    cin >> n;
    for(int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < a.size(); i++)
    {
        if(kt(a[i]))
        {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
