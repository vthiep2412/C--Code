#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long unluckyDay = (k + 12) % 7;

    // Nếu là thứ 6 (6), thì có n ngày không may
    cout << (unluckyDay == 6 ? n : 0) << endl;

    return 0;
}
