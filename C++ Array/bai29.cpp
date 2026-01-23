#include <bits/stdc++.h>
using namespace std;

int main() {
    int n=9 ,cnt=0,cntArray=0,cntmax=0,prev2=0,prev=0;
    // cin >> n;
    vector<int> a={2,3,4,4,3,7,9,8,8};
    vector<int> b;
    // for (int j = 0; j < n; j++) {
    //     cin>>a[j];
    // }
    //count the non go up number
    for (int j = 0; j <= n; j++) {
        if(j<n && a[j] <= prev) {
            cnt++;
        }
        else {
            if(cnt > cntmax) {
                cntmax = cnt;
                cntArray = 1;
            }
            else if(cnt==cntmax)
            {
                cntArray++;
            }
            cnt = 1;
        }
        prev = a[j];
    }
    //print out all
    for(int i=0;i<=n;i++)
    {
        if(i<n && a[i] <= prev2){
            b.push_back(a[i]);
        }
        else
        {
            if(b.size()==cntmax)
            {
                for(int j=0;j<b.size();j++)
                {
                    cout<<b[j]<<" ";
                }
                cout<<endl;
            }
            b.clear();
        }
        prev2 = a[i];
    }
    cout<<cntArray<<endl;

}