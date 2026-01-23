#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int psum = a[0];
    cout << psum << " ";
    for(int i = 1; i < n; i++){
        psum += a[i];
        cout << psum << " ";
    }
    return 0;
}