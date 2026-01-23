#include <iostream>
#include <vector>
using namespace std;
#define ll long long

vector<ll> oioi(const vector<ll>& B) {
    ll n = B.size();
    vector<ll> A;
    ll sumA = B[0];
    int cnt = 2;
    for (ll i = 0; i < n; ++i) {
        if(i==0){
            A.push_back(B[i]);
            continue;
        }
        ll oi;
        oi = (B[i]*cnt)-sumA;
        A.push_back(oi);
        sumA += oi;
        cnt++;
    }
    return A;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("avgseq.inp", "r", stdin);
    freopen("avgseq.out", "w", stdout);
    ll n;
    cin >> n;
    vector<ll> B(n);
    for (ll i = 0; i < n; ++i) {
        cin >> B[i];
    }
    vector<ll> A = oioi(B);
    for (ll a : A) {
        cout << a << " ";
    }
    return 0;
}
