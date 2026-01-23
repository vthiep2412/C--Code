#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2; // Bắt đầu từ 2 (thừa số nguyên tố nhỏ nhất)

    while (i <= sqrt(n)) {
        if (n % i == 0) { 
            cout << i << " "; 
            n /= i; 
        } else {
            if (i == 2) 
                i = 3; // Sau khi xử lý 2, chuyển sang 3
            else 
                i += 2; // Tăng dần i lên các số lẻ
        }
    }

    return 0;
}
