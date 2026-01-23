#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long b, n;
    cin >> n;

    int s = 0, cnt = 0; // Initialize cnt to 0
    while (n > 0) {
        s = n % 10;
        if (s == 8) {
            cnt += 2;
        } else if (s == 0 || s == 4 || s == 6 || s == 9) {
            cnt += 1;
        } else if (s == 1 || s == 2 || s == 3 || s == 5 || s == 7) {
            cnt += 0;
        }
        n /= 10;
    }

    cout << cnt << endl;
    return 0;
}
