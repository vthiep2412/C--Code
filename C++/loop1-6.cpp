//Nhập 2  số nguyên x và y, tính tổng bình phương từ x đến y.
//Ví dụ: x = 3 và y = 6 nên ta có tổng là 3^2 + 4^2 + 5^2 + 6^2 = 86.
#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int x, y, s;
    cout<< "Nhập số nguyên x: ";
    cin>>x;
    cout<< "Nhập số nguyên y: ";
    cin>>y;
    for (int i=x;i<=y;i+++)
    {
        s += pow(i, 2);
    }
    cout << "Tổng bình phương từ " << x << " đến " << y << " là: " << s << endl;
    return 0;
}