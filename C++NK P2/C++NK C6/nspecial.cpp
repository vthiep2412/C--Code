#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
typedef unsigned long long ull; 
typedef long double ld;
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back

ll sumDigits(ll k) {
    ll sum = 0;
    while (k > 0) {
        sum += k % 10;
        k /= 10;
    }
    return sum;
}

bool isSpecial(ll num) {
    ll original_num = num;
    ll s_num = sumDigits(num);
    ll s_factors = 0;
    ll temp = num;

    for (ll i = 2; i * i <= temp; ++i) {
        if (temp % i == 0) {
            ll s_i = sumDigits(i);
            while (temp % i == 0) {
                s_factors += s_i;
                temp /= i;
            }
        }
    }

    if (temp > 1) {
        s_factors += sumDigits(temp);
    }
    if (temp == original_num) return false;

    return s_num == s_factors;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("NSPECIAL.INP", "r", stdin);
    freopen("NSPECIAL.OUT", "w", stdout);

    ll n;
    if (cin >> n) {
        ll ans = n + 1;
        while (true) {
            if (isSpecial(ans)) {
                cout << ans;
                break;
            }
            ans++;
        }
    }

    return 0;
}