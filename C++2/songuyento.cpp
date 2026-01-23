#include <iostream>
using namespace std;

int main()
{
    int n,a=0;
    bool b = true;
    cout << "Nhập vào một số nguyên: ";
    cin >> n;

    if (n < 2) {
        cout << "none" << endl;
    }
     else {
        for (int m = 2; m <= n; m++)
        {
        b=true;
        for (int i = 2; i < m; i++) {
            if (m % i == 0) {
                b = false;
            }
        }
        if(b!=false)
        {
            cout<<m<<" ";
        }
        }
        

    }
    return 0;
}