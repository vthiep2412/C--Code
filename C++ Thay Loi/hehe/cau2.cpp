#include <bits/stdc++.h>
using namespace std;

string maxNumber(string s, int k) {
    vector<char> st;
    int toRemove = s.size() - k; // how many digits we can drop

    for (char c : s) {
        while (!st.empty() && toRemove > 0 && st.back() < c) {
            st.pop_back();
            toRemove--;
        }
        st.push_back(c);
    }

    // keep only k digits
    st.resize(k);

    return string(st.begin(), st.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);

    string ST;
    long long K;
    cin >> ST >> K;

    string ST1 = "";
    for (char c : ST) {
        if (isdigit(c)) ST1 += c; 
    }

    string result = maxNumber(ST1, K);
    if (result == "0") cout << 0;
    else cout << result;
    return 0;
}
