#include <bits/stdc++.h>
using namespace std;

long long solve(long long w, long long d, long long m) {
    long long thangle = 0, thangchan = 0;
    thangchan = (m - 1) / 2;
    thangle = (m) / 2;
    long long tongNgay = (thangle * 31 + thangchan * 30) + (d-1);
    long long thu = (w + tongNgay) % 7;
    return (thu == 0) ? 7 : thu;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("CALENDAR.INP", "r", stdin);
    freopen("CALENDAR.OUT", "w", stdout);
    long long w,d,m;
    cin >> w >> d >> m;
    cout << solve(w,d,m);
    return 0;
}
