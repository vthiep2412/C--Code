#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("pumpks.inp", "r", stdin);
    freopen("pumpks.out", "w", stdout);
    long long n=20;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin>>a[i]; 
    }
    long long sum=0;
    for(long long i=0;i<n;i++){
        sum+=a[i];
        if(sum==200){
            cout<<200;
            break;
        } else if(sum>200){
            if(200-(sum-a[i])<abs(sum-200)){ 
                cout<<200-(sum-a[i]);
                break;
            } else {
                cout<<sum;
                break;
            }
        }
    }
    return 0;
}