
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define all(a) a.begin(), a.end()

struct erm{
    ll val;
    ll orgIndex;
};

bool cmp(erm x, erm y){
    return x.val < y.val;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("MAXPRODUCT.inp", "r", stdin);
    freopen("MAXPRODUCT.out", "w", stdout);
    ll n, T;
    cin >> n >> T;
    
    vector<erm> a(n);

    for(int i=0; i<n;i++){
        cin >> a[i].val;
        a[i].orgIndex = i;
    }

    sort(all(a), cmp);
    ll left = 0, right = n - 1;
    ll max_product_val = -1;
    pair<ll,ll> ans = {-1,-1};
    
    while(left < right){
        if (a[right].val > T / a[left].val) {
            right--;
        } else {
            ll current_product = a[left].val * a[right].val;
            if (current_product > max_product_val) {
                max_product_val = current_product;
                ans = {a[left].orgIndex, a[right].orgIndex};
            }
            left++;
        }
    }
    
    if (ans.first == -1) {
        cout << "0\n";
    } else {
        cout << max_product_val << "\n";
        if (ans.first > ans.second) swap(ans.first, ans.second);
        cout << ans.first + 1 << " " << ans.second + 1 << "\n";
    }
    
    return 0;
}