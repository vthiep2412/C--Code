#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;
    if (x > 25) {
        if (x >= 26) {
            if (x >= 28) {
                cout << "Gioi" << endl;
            } else {
                cout << "Kha" << endl;
            }
        } else {
            cout << "TB" << endl;
        }
    } else {
        if (x == 25) {
            cout << "Yeu" << endl;
        } else {
            cout << "KW" << endl;
        }
    }

    return 0;
}
