#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("INCPOWER.INP", "r")){
        freopen("INCPOWER.INP", "r", stdin);
        freopen("INCPOWER.OUT", "w", stdout);
    }

    long double p;
    int n;
    long double d;
    cin >> p >> n >> d;

    vector<int> a(n);
    for(int &x : a) cin >> x;

    sort(a.begin(), a.end());

    for(int x : a){
        long double res1 = p + d;
        long double res2 = p * (1.0 + x / 100.0);
        p = max(res1, res2);
    }

    cout << fixed << setprecision(6) << p;

    return 0;
}