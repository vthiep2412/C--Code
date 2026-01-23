#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("demcap.inp", "r", stdin);
    // freopen("demcap.out", "w", stdout);
    int n=10;
    // cin >> n;
    vector<int> a = {1,1,1,2,2,2,4,5,2,2};
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    // }
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(a[i] == a[j]&& i != j) {
                cnt++;
            }
        }
    }
    cout << cnt;
}