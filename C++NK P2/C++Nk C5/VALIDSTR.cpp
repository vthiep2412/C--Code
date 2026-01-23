#include <bits/stdc++.h>
using namespace std;

bool isValidString(const string &s) {
    unordered_map<char, int> freq;
    for (char c : s) freq[c]++;

    vector<int> counts;
    for (auto &p : freq) counts.push_back(p.second);

    sort(counts.begin(), counts.end());
    if (counts.front() == counts.back()) return true;
    if (counts.front() == 1 && counts[1] == counts.back()) return true;
    if (counts.back() - counts[counts.size() - 2] == 1 &&
        counts[counts.size() - 2] == counts.front()) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("VALIDSTR.INP", "r", stdin);
    freopen("VALIDSTR.OUT", "w", stdout);

    string s;
    cin >> s;

    cout << (isValidString(s) ? "YES\n" : "NO\n");

    return 0;
}
