#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O3")

void insertBrackets(string &s, bool choice) {
    int pos = s.find_last_of('(');
    if (pos != string::npos)
        s.insert(pos + (choice ? 2 : 1), "()");
}

void PoPafterPop(long long n, vector<long long> &Ofcnt) {
    Ofcnt.pop_back();
    while (!Ofcnt.empty() && (Ofcnt.back() -= n + 2) == 0)
        PoPafterPop(Ofcnt.back(), Ofcnt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<long long> Ofcnt;
    string ans;
    long long nhap, prev = 0;
    for (int i = 0; i < n; i++) {
        cin >> nhap;
        if (nhap) {
            ans += (ans.empty() || Ofcnt.empty()) ? "()" : (insertBrackets(ans, prev == 0), "");
            Ofcnt.push_back(nhap);
        } else {
            if (ans.empty() || Ofcnt.empty()) ans += "()";
            else {
                long long &temp = Ofcnt.back();
                if (temp - 2 == 0) insertBrackets(ans, prev == 0), PoPafterPop(temp, Ofcnt);
                else temp -= 2, insertBrackets(ans, prev == 0);
            }
        }
        prev = nhap;
    }
    cout << ans;
    return 0;
}
