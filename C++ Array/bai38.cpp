#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,input;
    cin>>n;
    vector<int> a(n);
    for (int j=0;j<n;j++)
    {
        cin>>a[j];
    }
    cin>>input;
    a.push_back(input);
    for (int j=0;j<a.size();j++)
    {
        cout<<a[j]<<" ";
    }
}