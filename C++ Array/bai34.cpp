#include <bits/stdc++.h>
using namespace std;

int main() {
    int f=0,e=0,cnt=1;
    cin >> f;
    vector<int> a;
    vector<int> b(f);
    for (int j = 0;j < b.size(); j++) {
        cin>>b[j];
    }
    cin >> e;
    vector<int> c(e);
    for (int j = 0;j < c.size(); j++) {
        cin>>c[j];
    }
    a.insert(a.end(), b.begin(), b.end());
    a.insert(a.end(), c.begin(), c.end());
    for (int j = 0; j < a.size(); j++) {
        cout<<a[j]<<" ";
    }

}