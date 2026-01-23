#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

vector<int> a;
string s;

// to_string: convert int to string
// manually
string ToString(int n){
    stringstream ss;
    ss<<n;
    return ss.str();
}

//recursion
void numgen(int n, string &s){
    if(n==0){
        cout<<s<<"\n";
        return;
    }
    for(int i=0;i<a.size();i++){
        s+=ToString(a[i]);
        numgen(n-1, s);
        s.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int n,k;
    cin>>n>>k;
    a.resize(n);
    for(int i=1;i<=n;i++){
        a[i-1]=i;
    }
    numgen(k, s);
    return 0;
}