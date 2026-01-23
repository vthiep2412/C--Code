#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back



int fibonacci(int n, vector<int> &memo){
    if(n==0) return 0;
    if(n==1) return 1;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("fibonacci.inp", "r", stdin);
    //freopen("fibonacci.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> memo(n+1,-1);
    cout<<fibonacci(n,memo);
    return 0;
}