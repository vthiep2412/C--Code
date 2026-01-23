#include <bits/stdc++.h>

using namespace std;

int sovle(vector<pair<int, int>> a, int m){
    int sum = 0;
    vector<int> b;
    sort(a.begin(), a.end());
    cout<<"\n";
    for(int i = 0; i < a.size(); i++){
        cout << a[i].first << " " << a[i].second << "\n"; 
    }
    cout<<"\n";
    for(int i = 0; i < a.size(); i++){
        b.push_back(a[i].first);
        sum += a[i].second;
        if(sum >= m){
            return *max_element(b.begin(), b.end());
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    cout << sovle(a, m) << "\n";
    
    return 0;
}
