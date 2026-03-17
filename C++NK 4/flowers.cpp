#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("flowers.inp", "r", stdin);
    freopen("flowers.out", "w", stdout);
    int a,b,c,maxi=0;
    cin>>a>>b>>c;
    for(int h1=0;h1<=c/a;h1++){
        int h2=(c-a*h1)/b;
        maxi = max(maxi,h1*a+h2*b);
    }
    cout<<maxi;
}