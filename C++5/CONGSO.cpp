#include <bits/stdc++.h>
using namespace std;

long long PT1(vector<long long> a, vector<long long> b) {
    return a[0] + b[0];
} long long PT2(vector<long long> a, vector<long long> b) {
    return a[a.size() - 1] + b[b.size() - 1];
} long long PT3(vector<long long> a, vector<long long> b) {
    return a[0] + b[b.size() - 1]; 
} long long PT4(vector<long long> a, vector<long long> b) {
    return a[a.size() - 1] + b[0]; 
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CONGSO.inp", "r", stdin);
    freopen("CONGSO.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<long long> a(n), b(m);
    for (long long i = 0; i < n; ++i) {
        cin >> a[i]; 
    } for (long long i = 0; i < m; ++i) {
        cin >> b[i]; 
    }
    sort(a.begin(), a.end(), less<long long>());
    sort(b.begin(), b.end(), less<long long>());
    if(s == "PT1"){
        cout << PT1(a, b);
    } else if(s == "PT2"){
        cout << PT2(a, b); 
    } else if(s == "PT3"){
        cout << PT3(a, b); 
    } else if(s == "PT4"){
        cout << PT4(a, b);
    }
    return 0;
}