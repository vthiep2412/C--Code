#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll countSTH(string s, char c){
    ll cnt=0;
    for(char x:s) if(x==c) cnt++;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("repstr.inp", "r", stdin);
    freopen("repstr.out", "w", stdout);
    string s;
    cin>>s;
    ll n;
    cin>>n;
    ll len=s.length();
    ll cnt = countSTH(s, 'a');
    if(n>len){
        ll uhh = n/len;
        cnt = cnt * uhh;
        ll rem = n - (len * uhh);
        string t = s.substr(0, rem);
        cnt += countSTH(t, 'a');
    }else{
        string t = s.substr(0, n);
        cnt = countSTH(t, 'a');
    }
    cout<<cnt;
    return 0;
}