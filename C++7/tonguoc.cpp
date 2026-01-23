#include <bits/stdc++.h>
using namespace std;

vector<int> timUoc(int n) {
    vector<int> v;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            v.push_back(i);
            if (i != n / i) {
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("tonguoc.inp", "r", stdin);
    freopen("tonguoc.out", "w", stdout);
    int n,k,sum=0,cnt=0;
    cin>>n>>k;
    vector<int> v = timUoc(n);
    for(int i:v){
        if(i%k==0){
            sum+=i;
            cnt++;
        }
    }
    cout<<cnt<<"\n"<<sum;
    return 0;
}