#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("khohang.inp", "r", stdin);
    // freopen("khohang.out", "w", stdout);
    int n;
    vector<int> a;
    int sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        if(s == "N"){
            int m;
            cin >> m;
            a.insert(a.begin(), m);
            sum+=m;
        } else if (s == "X") {
            sum-=a.back();
            a.pop_back();
            cout << sum << "\n";
        } else {
            cout << "Error: Invalid command\n";
        }
    }
    return 0;
}