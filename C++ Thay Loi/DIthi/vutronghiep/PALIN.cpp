#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("palin.inp", "r", stdin);
    freopen("palin.out", "w", stdout);
    string s;
    cin>>s;
    int r=0,l=s.size()-1;
    bool isodd = (s.size()%2==1);
    while(r<l){
        if(isodd && (r==l)) break;
        if(s[r]!=s[l]){
            cout<<"NO";
            return 0;
        }
        r++;
        l--;
    }
    cout<<"YES";
    return 0;
}