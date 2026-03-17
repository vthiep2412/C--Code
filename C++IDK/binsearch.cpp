#include <bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int n,k,nhap;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<k;i++){
        cin>>nhap;
        cout<<binary(a,k)+1<<"\n";
    }
    return 0;
}