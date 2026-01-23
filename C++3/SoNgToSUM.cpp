#include <bits/stdc++.h>

using namespace std;
// để lại


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
void kt2(int n)
{
    int y, x;
    for (int x = 2; x <= n / 2; x++)
    {
        y = n - x;
        if (kt(x) && kt(y))
        {
            if (y + x == n) {
                cout << x << " " << y << endl;
            }
        }
    }
}



int main() {
    int a=8, b=9, n=21;

    int maxVal = 0;

    for (int x = 0; x <= n / 2; x++) {
        for (int y = 0; y <= n / 2; y++) {
            int val = a * x + b * y;
            if (val <= n && val > maxVal) {
                maxVal = val;
            }
        }
    }

    cout << maxVal << endl;
    return 0;
}
