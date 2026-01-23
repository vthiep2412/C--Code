//cach cu

// #include <bits/stdc++.h>
// using namespace std;

// bool kt(long long n){
//     if (n < 2) return false;
//     if (n == 2 || n == 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     const long long c2 = sqrt(n);
//     for (long long i = 5; i <= c2; i += 6) {
//         if (n % i == 0 || n % (i + 2) == 0) return false;
//     }
//     return true;
// }

// int cntNT(int l, int r) {
//     int cnt = 0;
//     for (int i = l; i <= r; ++i) {
//         if (kt(i)) cnt++;
//     }
//     return cnt;   
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     freopen("DOANNT.inp", "r", stdin);
//     freopen("DOANNT.out", "w", stdout);
//     int q;
//     cin >> q;
//     for (int i = 0; i < q; ++i) {
//         int l,r;
//         cin >> l >> r;
//         cout << cntNT(l, r) << "\n";
//     }
//     return 0;
// }

// cach moi
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 1;

vector<int> prime(maxn, 1);
vector<int> prefix(maxn, 0);

void sang(){
    prime[0] = prime[1] = 0;
    for (int i = 2; i * i <= maxn - 1; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= maxn - 1; j += i) {
                prime[j] = 0;
            }
        }
    }
    for (int i = 1; i <= maxn - 1; i++) {
        prefix[i] = prefix[i - 1] + prime[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DOANNT.inp", "r", stdin);
    freopen("DOANNT.out", "w", stdout);
    sang();
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << "\n";
    }
    return 0;
}

