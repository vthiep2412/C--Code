 #include <bits/stdc++.h>
using namespace std;

int main() {
    int n, cnt = 0, cnt2 = 0, cntmax = 0, cnt3 = 0;
    cin >> n;
    int a[n]={1,2,-3,4,5,6,-7,8,9,10};
    vector<int> b;

    // for (int j = 0; j < n; j++) {
    //     cin >> a[j];
    // }
    //count the highest number of positive numbers
    for (int j = 0; j < n; j++) {
        if(a[j] > 0) {
            cnt++;
        }
        else {
            if(cnt > cntmax) {
                cntmax = cnt;
                cnt2 = 1;
            }
            else if(cnt==cntmax)
            {
                cnt2++;
            }
            cnt = 0;
        }
    }
    //print out all
    for(int i =0;i<n;i++)
    {
        if(a[i]>0){
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
    }
    cout<<cnt2;

}