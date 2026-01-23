#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int x, y, s;
    cout<< "Nhập số nguyên thứ 1: ";
    cin>>x;
    cout<< "Nhập số nguyên thứ 2: ";
    cin>>y;
    for (int i=x;i<=y;i++)
    {
        s += i;
    }
    cout << "Tổng bình phương từ " << x << " đến " << y << " là: " << s << endl;
    return 0;
}