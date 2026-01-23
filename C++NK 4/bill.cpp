#include <iostream>
using namespace std;

#define elif else if

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("bill.inp","r",stdin);
    // freopen("bill.out","w",stdout);
    long long n,sum=0;
    cin>>n;
    if(1<=n && n<=50){
        sum = n*14;
    }
    elif (51<=n && n<=100){
        sum = (50*14)+(n-50)*15;
    }
    elif (101<=n && n<=200){
        sum = (50*14)+(100-50)*15+(n-100)*16; 
    }
    elif (201<=n && n<=300){
        sum = (50*14)+(100-50)*15+(200-100)*16+(n-200)*17; 
    }
    elif (301<=n && n<=400){
        sum = (50*14)+(100-50)*15+(200-100)*16+(300-200)*17+(n-300)*18; 
    }
    elif (401>=n){
        sum = (50*14)+(100-50)*15+(200-100)*16+(300-200)*17+(400-300)*18+(n-400)*20; 
    }
    cout<<sum;
}