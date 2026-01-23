#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

vector<int> a;
string s;

//recursion
void bingen(int n, string &s){
    if(n==0){
        cout<<s<<"\n";
        return;
    }
    s.push_back('0');
    bingen(n-1, s);
    s.pop_back();
    s.push_back('1');
    bingen(n-1, s);
    s.pop_back();
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    int n;
    cin>>n;
    bingen(n, s);
    return 0;
}