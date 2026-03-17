#include<bits/stdc++.h>
using namespace std;

bool hasA[1000005], hasB[1000005];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("MAXGCD.INP", "r", stdin);
    freopen("MAXGCD.OUT", "w", stdout);

    int n,v, maxV=-1;
    cin >> n;
    int n2=n;
    while(n--){
        cin>>v;
        hasA[v] = 1;
        maxV = max(maxV,v);
    }
    while(n2--){
        cin>>v;
        hasB[v] = 1;
        maxV = max(maxV,v);
    }
    
    for(int g= maxV;g>=1;g--){
        int m1=0,m2=0;
        for(int v1=g;v1<=maxV;v1+=g){
            if(hasA[v1]) m1=v1;
            if(hasB[v1]) m2=v1;
        }
        if(m1 and m2) {cout<<m1+m2;return 0;}
    }
    

    return 0;
}