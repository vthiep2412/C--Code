#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void genSub(const vector<ll>& nums, vector<pair<ll, ll>>& subsets) {
    int n = nums.size();
    for (int i = 0; i < (1 << n); ++i) {
        ll sum = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) sum += nums[j];
        }
        subsets.push_back({sum, i});
    }
}

int findtar(long long tar, const vector<pair<long long, long long>>& arr) {
    int l = 0;
    int h = (int)arr.size() - 1;

    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid].first == tar) return mid;
        
        if (arr[mid].first < tar) l = mid + 1;
        else h = mid - 1;
    }
    
    return -1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("CHONSO.INP", "r", stdin)
    // freopen("CHONSO.OUT", "w", stdout);

    int n; cin >> n;
    vector<ll> a(n);
    for (ll &x:a) cin >> x;
    ll M; cin >> M;

    int n1 = n / 2;
    vector<ll> left(a.begin(), a.begin() + n1);
    vector<ll> right(a.begin() + n1, a.end());

    vector<pair<ll, ll>> left, right;
    
    genSub(left, left);
    genSub(right, right);

    sort(left.begin(), left.end());

    for (auto& p : right) {
        long long tar = M - p.first;
        int idx = findtar(tar, left);
        if (idx != -1) {
            for (int i = 0; i < n1; ++i) {
                cout << ((left[idx].second >> i) & 1);
            }
            for (int i = 0; i < right.size(); ++i) {
                cout << ((p.second >> i) & 1);
            }
            return 0;
        }
    }
    return 0;
}