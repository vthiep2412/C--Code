#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,sum=0,cnt2=0,maxval=0,sum2=0;
    cin >> n;
    int a[n];
    vector<int> b;
    for (int j = 0; j < n; j++) {
        cin>>a[j];
    }
    //count the highest number of positive numbers
    for (int j = 0; j <= n; j++) {
        if(j<n && a[j] > 0) {
            sum += a[j];
        }
        else {
            if(sum > maxval) {
                maxval = sum;
                cnt2 = 1;
            }
            else if(sum==maxval)
            {
                cnt2++;
            }
            sum = 0;
        }
    }
    //print out all
    for(int i =0;i<=n;i++)
    {
        if(i<n && a[i]>0){
            sum2 += a[i];
            b.push_back(a[i]);
        }
        else
        {
            if(sum2==maxval)
            {
                for(int j=0;j<b.size();j++)
                {
                    cout<<b[j]<<" ";
                }
                cout<<endl;
            }
            b.clear();
            sum2 = 0;
        }
    }
    cout<<cnt2;

}