#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,dem=0,dem2=0;
    cin>>n;
    int a[n];
    for (int i =0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]==a[j])
            dem++;
        }
        if (dem2>dem){
            dem=dem2;
            dem2=0;
        }
    }
    cout<<dem;
    return 0;
}