#include <bits/stdc++.h>
using namespace std;

struct Student {
    int h, id;
};

bool cmp(const Student& a, const Student& b) {
    return a.h < b.h;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("LINEUP.INP", "r", stdin);
    freopen("LINEUP.OUT", "w", stdout);
    int n;
    cin >> n;

    vector<Student> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].h;
        a[i].id = i;
    }

    sort(a.begin(), a.end(), cmp);

    int max_len = 0, curr_len = 1;
    if (n == 0) curr_len = 0;

    for (int i = 1; i < n; i++) {
        if (a[i].id > a[i - 1].id) {
            curr_len++;
        } else {
            max_len = max(max_len, curr_len);
            curr_len = 1;
        }
    }
    max_len = max(max_len, curr_len);

    cout << n - max_len;
    return 0;
}