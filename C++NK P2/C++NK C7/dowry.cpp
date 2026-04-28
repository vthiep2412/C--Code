#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (fopen("dowry.inp", "r")) {
        freopen("dowry.inp","r",stdin);
        freopen("dowry.out","w",stdout);
    }
    int n;
    ll total = 0, target;
    cin >> n;
    vector<int> a(n);
    for(int &x : a){ 
        cin >> x;
        total += x;
    }
    if(total % 3 != 0){
        cout << -1 << "\n";
        return 0;
    }
    target = total / 3;
    vector<int> valid;
    int c = (1 << n);
    for(int mask = 0; mask < c; mask++){
        ll curSum = 0;
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) curSum += a[i];
        }
        if(curSum == target) valid.push_back(mask);
    }
    vector<string> results;
    for (int m_a : valid) {
        for (int m_b : valid) {
            if ((m_a & m_b) == 0) {
                string current = "";
                for (int i = 0; i < n; ++i) {
                    if ((m_a >> i) & 1) current += 'A';
                    else if ((m_b >> i) & 1) current += 'B';
                    else current += 'C';
                }
                results.push_back(current);
            }
        }
    }

    if (results.empty()) {
        cout << -1 << "\n";
    } else {
        cout << results.size() << "\n";
        for (const string& s : results) {
            cout << s << "\n";
        }
    }
    return 0;
}