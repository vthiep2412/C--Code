#include <bits/stdc++.h>
using namespace std;

vector<long long> solve(long long n) {
    vector<long long> ans;
    long long i = 3;
    double a = sqrt(n);
    while (n % 2 == 0) {   
        ans.push_back(2);
        n = n / 2;
    }
    while (i <= a) {
        if (n % i == 0) {
            ans.push_back(i);
            n = n / i;
        } else {
            i = i + 2;
        }
    }
    if (n > 1) {
        ans.push_back(n);
    }
    return ans;
}

int main() {
    long long n;
    cin >> n;
    vector<long long> ans = solve(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}