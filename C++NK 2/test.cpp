#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,t,cnt;
    cin >> n >> t;
    vector<int> a(n);
    for(int i = 0;i<a.size();i++){
        cin>>a[i];
    }
    for(int i = 0;i<a.size();i++){
        int s = 0;
        for(int j = i;j<a.size();j++){
            s += a[j];
            if(s==t){
                cnt++;
                s = 0;
                break;
            }
        }
    }
    cout<<cnt;
}