#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,cnt;
    cin >> n;
    vector<int> a(n);
    int c = a.size();
    for (int i = 0; i < c; i++)
    {
        cin >> a[i];
    }
    int s1,s2,s3;
    for(int s1=0;s1<c;s1++)
    {
        for(int s2=0;s2<c;s2++)
        {
            for(int s3=s2+1;s3<c;s3++)
            {
                if(a[s2]-a[s1]==a[s3]-a[s2])
                {
                    cnt++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}