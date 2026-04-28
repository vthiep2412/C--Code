#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // Filenames must match the problem description EXACTLY (Case-sensitive)
    if (fopen("DOWRY.INP", "r")) {
        freopen("DOWRY.INP", "r", stdin);
        freopen("DOWRY.OUT", "w", stdout);
    }
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> a(n);
    ll total = 0;
    for(int i = 0; i < n; i++){ 
        cin >> a[i];
        total += a[i];
    }

    // Preliminary check
    if(total % 3 != 0){
        cout << -1 << "\n";
        return 0;
    }

    ll target = total / 3;
    vector<int> valid;
    
    // 1. Find all valid subsets
    int num_subsets = (1 << n);
    for(int mask = 0; mask < num_subsets; mask++){
        ll curSum = 0;
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) curSum += a[i];
        }
        if(curSum == target) valid.push_back(mask);
    }

    // 2. Find disjoint pairs (Son A and Son B)
    vector<string> results;
    for (int m_a : valid) {
        for (int m_b : valid) {
            if ((m_a & m_b) == 0) {
                string s = "";
                for (int i = 0; i < n; i++) {
                    if ((m_a >> i) & 1) s += 'A';
                    else if ((m_b >> i) & 1) s += 'B';
                    else s += 'C';
                }
                results.push_back(s);
            }
        }
    }

    // 3. Final Output
    if (results.empty()) {
        cout << -1 << "\n";
    } else {
        // Sorting ensures alphabetical order as seen in the example
        sort(results.begin(), results.end());
        cout << results.size() << "\n";
        for (const string& s : results) {
            cout << s << "\n";
        }
    }

    return 0;
}