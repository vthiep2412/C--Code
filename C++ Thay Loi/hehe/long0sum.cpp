#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("long0sum.inp", "r", stdin);
    //freopen("long0sum.out", "w", stdout);
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    map<int, int> psm;
    int curPS = 0;
    int maxL = 0;
    int endI = -1;
    psm[0] = -1;

    for(int i=0; i<n; i++) {
        curPS += a[i];

        if(psm.count(curPS)) {
            if(i - psm[curPS] > maxL) {
                maxL = i - psm[curPS];
                endI = i;
            }
        } else {
            psm[curPS] = i;
        }
    }

    if (maxL == 0) {
        cout << "NOT FOUND" << endl;
    } else {
        for (int i = endI - maxL + 1; i <= endI; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    return 0;
}