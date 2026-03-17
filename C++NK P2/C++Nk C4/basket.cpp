#include <bits/stdc++.h>
using namespace std;

int toSec(const string &s) {
    int m, sec;
    sscanf(s.c_str(), "%d:%d", &m, &sec);
    return m * 60 + sec;
}

string DtoT(int totalSec) {
    int m = totalSec / 60;
    int s = totalSec % 60;
    char buf[6];
    sprintf(buf, "%02d:%02d", m, s);
    return string(buf);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("BASKET.INP", "r", stdin);
    freopen("BASKET.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; ++i) {
        int x;
        string s;
        cin >> x >> s;
        b.push_back(x);
        a.push_back(toSec(s));
    }
    int doi1 = 0, doi2 = 0, last = 0, sc1 = 0, sc2 = 0;
    for (int i = 0; i < n; ++i) {
        int cur = a[i];
        if (sc1 > sc2) doi1 += cur - last;
        else if (sc2 > sc1) doi2 += cur - last;
        if (b[i] == 1) sc1++;
        else sc2++;
        last = cur;
    }
    int DuP = 48 * 60;
    if (sc1 > sc2) doi1 += DuP - last;
    else if (sc2 > sc1) doi2 += DuP - last;
    cout << DtoT(doi1) << "\n" << DtoT(doi2);
    return 0;
}
