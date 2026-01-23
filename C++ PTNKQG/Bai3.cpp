#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main() {
    int n, cnt = 0;
    string c, a, d;
    cin >> n;
    auto start = high_resolution_clock::now();
    for (int i = 1; i <= n; i++) {
        c = to_string(i);
        a += c;
    }
    for (char i : a) {
        cnt++;
        if (cnt >= n) {
            if (cnt >= n + 4) { break; }
            cout << i;
        }
    }

    auto stop = high_resolution_clock::now(); // Stop time
    duration<double> duration = stop - start;
    cout << "\nTime taken by function: " << duration.count() << " seconds" << endl;
}