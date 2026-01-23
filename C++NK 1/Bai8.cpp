#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    if (a + b == c + d) {
        cout << "5" << endl;
    } else {
        if (a == c) {
            if (a == e) {
                cout << "3" << endl;
            } else {
                cout << "1" << endl;
            }
        } else {
            if (b == a) {
                cout << "4" << endl;
            } else {
                cout << "2" << endl;
            }
        }
    }

    return 0;
}
    