#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct e {
    ll start, end;
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("lehoi.inp","r",stdin);
    // freopen("lehoi.out","w",stdout);
    ll n, cnt=1;
    cin>>n;
    vector<e> a(n);
    for(e &x:a) 
        cin>>x.start>>x.end;
    sort(a.begin(), a.end(), [](const e &a, const e &b){
        return a.end < b.end;
    });
    ll lastEnd = a[0].end;
    for(int i=1; i<n;i++)
        if(a[i].start >= lastEnd) {
            cnt++;
            lastEnd = a[i].end;
        }
    cout<<cnt;
    return 0;
}