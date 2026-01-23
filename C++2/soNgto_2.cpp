#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, a = 0, b = 0,sum = 0;
    cout << "Nhập vào một số nguyên: ";
    cin >> n;

    if (n < 2) {
        cout << "none" << endl;
    } else {
        for (int m = 2; m <= n; m++) {
            b = 0; 
            for (int i = 2; i < m; i++) {
                if (m % i == 0) {
                    b = 1; 
                    break;
                }
            }
            if (b != 1) {
                cout << m << " ";
                sum += m;
            }
        }
        cout<<"\n";
        cout<<sum<<endl;
    }
    return 0;
}