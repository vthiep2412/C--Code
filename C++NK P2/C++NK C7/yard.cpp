#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(a) a.begin(), a.end()
const int MAXN = 230000;

vector<int> f = {1, 1, 1, 1, 2, 3, 4, 5, 7, 10, 14, 19, 26, 36, 50, 69, 95, 131, 181, 250, 345, 476, 657, 907, 1252, 1728, 2385, 3292, 4544, 6272, 8657, 11949, 16493, 22765, 31422, 43371, 59864, 82629, 114051, 157422, 217286};
vector<char> isP(MAXN+5,1);
vector<int> Pref(MAXN+6,0);
void sieve(){
    isP[0]=isP[1]=0;
    for(int i=2;i*i<=MAXN;i++){
        if(isP[i])
            for(int j=i*i;j<=MAXN;j+=i){
                isP[j]=0;
            }
    }
}

void build(){
    for(int i=1;i<=MAXN+5;i++)
        Pref[i] = Pref[i-1]+isP[i];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("yard.inp", "r", stdin);
    freopen("yard.out", "w", stdout);
    sieve();
    build();
    int t,x;
    cin>>t;
    while(t--){
        cin>>x;
        cout<<Pref[f[x]]<<"\n";
    }
    return 0;
}