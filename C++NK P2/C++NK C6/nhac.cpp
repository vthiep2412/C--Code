#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct S {
    int id;
    long long dur;
};

bool cmp(const S& x, const S& y) {
    if (x.dur != y.dur) return x.dur < y.dur;
    return x.id < y.id;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen("NHAC.INP", "r", stdin))
    freopen("NHAC.OUT", "w", stdout)

    int n;
    cin >> n;
    
    vector<S> a(n);
    for(int i=0;i<a.size();i++){
        cin>>a[i].dur;
        a[i].id = i+1;
    }
    
    sort(a.begin(), a.end(),cmp);
    
    long long total = 0;
    long long cur = 0;
    
    for (int i = 0; i < n; i++) {
        cur += a[i].dur;
        cout << a[i].id << " " << cur << "\n";
        total += cur;
    }

    cout << total << "\n";

    return 0;
}