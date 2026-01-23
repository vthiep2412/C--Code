#include <bits/stdc++.h>
using namespace std;

struct e{
    long long nhan;
    long long sum;
    pair<long,long> cu;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("QUA.INP", "r", stdin);
    // freopen("QUA.OUT", "w", stdout);

    long long n;
    if (!(cin >> n)) { cerr << 0; return 0; }
    cerr << "Debug: Read n = " << n << endl;

    vector<long long> a(n), w(n);
    for (long long i = 0; i < n; ++i) cin >> a[i] >> w[i];
    
    cerr << "Debug: Input arrays a and w:" << endl;
    cerr << "a: "; for(long long val : a) cerr << val << " "; cerr << endl;
    cerr << "w: "; for(long long val : w) cerr << val << " "; cerr << endl;

    vector<e> ee;
    for (long long i = 0; i < n; ++i){
        cerr << "\nDebug: Processing a[i]=" << a[i] << ", w[i]=" << w[i] << " at index " << i << endl;
        if(ee.empty() == true) {
            ee.push_back({a[i], w[i], {a[i], w[i]}});
            cerr << "Debug: ee was empty. Pushed {" << a[i] << ", " << w[i] << ", {" << a[i] << ", " << w[i] << "}}" << endl;
            continue;
        }
        bool oke = false;
        cerr << "Debug: ee is not empty. Current ee elements:" << endl;
        for(size_t j = 0; j < ee.size(); ++j) {
            cerr << "  ee[" << j << "]: {nhan=" << ee[j].nhan << ", sum=" << ee[j].sum << ", cu={" << ee[j].cu.first << ", " << ee[j].cu.second << "}}" << endl;
        }

        for(auto &x: ee){
            cerr << "Debug: Checking element x: {nhan=" << x.nhan << ", sum=" << x.sum << ", cu={" << x.cu.first << ", " << x.cu.second << "}}" << endl;
            // thu 1
            if(x.nhan < a[i]){
                cerr << "Debug: Condition 1 met (x.nhan <= a[i]). Updating x." << endl;
                x.nhan = a[i];
                x.sum += w[i];
                x.cu = {a[i],w[i]};
                oke = true;
                cerr << "Debug: x updated to: {nhan=" << x.nhan << ", sum=" << x.sum << ", cu={" << x.cu.first << ", " << x.cu.second << "}}" << endl;
            }else if(x.cu.second < w[i] && x.cu.first < a[i]){
                cerr << "Debug: Condition 2 met (x.cu.second < w[i] && x.cu.first <= a[i]). Updating x." << endl;
                x.nhan = a[i];
                x.sum -= x.cu.second;
                x.sum += w[i];
                x.cu = {a[i],w[i]};
                oke = true;
                cerr << "Debug: x updated to: {nhan=" << x.nhan << ", sum=" << x.sum << ", cu={" << x.cu.first << ", " << x.cu.second << "}}" << endl;
            } else {
                cerr << "Debug: No condition met for current x." << endl;
            }
        }
        if(oke == false){
            ee.push_back({a[i], w[i], {a[i], w[i]}});
            cerr << "Debug: oke is false. Pushed new element {" << a[i] << ", " << w[i] << ", {" << a[i] << ", " << w[i] << "}}" << endl;
        }
        cerr << "Debug: End of iteration " << i << ". Current ee elements:" << endl;
        for(size_t j = 0; j < ee.size(); ++j) {
            cerr << "  ee[" << j << "]: {nhan=" << ee[j].nhan << ", sum=" << ee[j].sum << ", cu={" << ee[j].cu.first << ", " << ee[j].cu.second << "}}" << endl;
        }
    }
    
    cerr << "\nDebug: Final ee elements before computing max sum:" << endl;
    for (auto &x : ee) {
        cerr << "  {nhan=" << x.nhan << ", sum=" << x.sum << ", cu={" << x.cu.first << ", " << x.cu.second << "}}" << endl;
    }

    // compute max sum
    long long ans = 0;
    for (auto &x : ee) {
        ans = max(ans, x.sum);
    }

    cout << ans;

    return 0;
}
