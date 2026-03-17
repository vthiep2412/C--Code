#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("MANG05.INP","r",stdin);
    freopen("MANG05.OUT","w",stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    if(n<2) return 0;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int min=INT_MAX,min2=INT_MAX;
    int iMin=0,iMin2=0;
    for(int i=0;i<n;i++){
        if(a[i]<min){
            min2=min;
            min=a[i];
            iMin2=iMin;
            iMin=i;
        }
        else if(a[i]<min2 && a[i]!=min){
            min2=a[i];
            iMin2=i;
        }
        else if(a[i]==min && iMin2==0 && i!=iMin){
            min2=min;
            iMin2=i;
        }
    }
    if(iMin2!=0) cout<<iMin+1<<" "<<iMin2+1;
    return 0;
}