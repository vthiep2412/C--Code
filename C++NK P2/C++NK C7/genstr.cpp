#include <bits/stdc++.h>
using namespace std;

bool nextPermutation(string& h) {
    int n = h.size();
    int i = n-2; int j = n-1;
    while (i >= 0 and h[i] >= h[i+1]) i--;
    if (i < 0) return false;
    while (h[j] <= h[i]) j--;
    swap(h[i], h[j]);
    reverse(h.begin() + i + 1, h.end());
    return true;
}

int main() {
    if (fopen("genstr.INP", "r")) {
        freopen("genstr.INP", "r", stdin);
        freopen("genstr.OUT", "w", stdout);
    }
    string s,org;
    cin>>s;
    sort(s.begin(),s.end());
    org = s;
    int cnt = 1;
    vector<string> ans;
    while(nextPermutation(s)){
        ans.push_back(s);
        cnt++;
    }
    cout<<cnt<<"\n";
    cout<<org<<"\n";
    for(string &c:ans) cout<<c<<"\n";
    return 0;
}