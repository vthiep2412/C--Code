#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("DISTANCE.INP", "r", stdin);
    freopen("DISTANCE.OUT", "w", stdout);
    string a,b;
    cin >> a >> b;
    int sum = 0;
    int maxi = max(a.length(), b.length());
    int mini = min(a.length(), b.length());
    if (a.length() < b.length()) {
        for (int i = 1; i <= maxi - mini; i++) {
            a.insert(a.begin(), '0');
        }
    }
    else if (b.length() < a.length()) {
        for (int i = 1; i <= maxi - mini; i++) {
            b.insert(b.begin(), '0');
        }
    }
    for(int i = 0; i < maxi; i++){
        const int x = a[i] - '0';
        const int y = b[i] - '0';
        sum += abs(x - y);
    }
    cout << sum;
    return 0;
}