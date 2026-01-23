#include <iostream>
#include <string>
using namespace std;


int main() {
    int n,s,a,b;
    cout << "Nhap so nguyen n: ";
    cin >> n;
    while(n>0)
    {
        b=n%10;
        n/=10;
        if (n > 0) {
            a=n%10;
            s+=abs(a-b);
        }
    }
    cout << "Tong gia tri chenh lech: " << s << endl;
    return 0;
}