#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(fopen("ALARM.INP", "r")){
        freopen("ALARM.INP", "r", stdin);
        freopen("ALARM.OUT", "w", stdout);
    }

    int n;
    cin >> n;

    int led[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    for (int h = 0; h < 24; h++) {
        for (int m = 0; m < 60; m++) {
            int tot = led[h / 10] + led[h % 10] + led[m / 10] + led[m % 10];
            
            if (tot == n) {
                if (h < 10) cout << "0";
                cout << h << ":";
                if (m < 10) cout << "0";
                cout << m << "\n";
                return 0;
            }
        }
    }
    cout << "Impossible\n";
    return 0;
}