#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("BIRTHCAKES.inp", "r", stdin);
    freopen("BIRTHCAKES.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0,
        j = n / 2,
        pairs = 0;
    while(i < n/2 && j < n){
        if( a[i] * 2 <= a[j] ){
            pairs++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }
    cout << (n - pairs) << "\n";
    return 0;
}
