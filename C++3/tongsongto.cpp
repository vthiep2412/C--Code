#include <iostream>
#include <math.h>
using namespace std;

bool kt(int num)
{
    bool b = true;
    if(num>1){
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                b=false;
                }
            }
    }
    else {b=false;}
    return b;
}

void kts(int num) {
    bool b = false;
    for (int i = 2; i <= num / 2; i++) {
        if (kt(i) && kt(num - i)) {
            cout << i << " " << num - i << endl;
            b = true;
        }
    }
    if (b!=true) {cout << num << endl;
    }
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    kts(num);
    return 0;
}