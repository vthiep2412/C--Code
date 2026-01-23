#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,input;
    // cin>>n;
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    a.insert(a.begin()+3,100);
    for (int j=0;j<a.size();j++)
    {
        cout<<a[j]<<" ";
    }
}