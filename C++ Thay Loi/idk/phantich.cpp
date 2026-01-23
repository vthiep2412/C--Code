#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

vector<ll> a;

void phantich(ll target){
    ll sum=target;
    printarr();
    while(true){
        // normal occur
        if(sum == target){
            ll temp = a.back();
            a.pop_back();
            a.back() += temp;
        } else if(sum<target) {

        }
        printarr();
    }
}

void printarr(){
    for(ll i=0;i<a.size();++i){
        cout<<a[i]<<' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("phantich.inp", "r", stdin);
    //freopen("phantich.out", "w", stdout);
    ll n;
    cin>>n;
    a.resize(n,1);
    
    return 0;
}