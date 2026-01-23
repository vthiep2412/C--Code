#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long b,n;
    cin>>b;
    n=trunc(b);

    int s = 0,cnt;
    while (n > 0) {
        s = n % 10;
        n /= 10;
        cnt +=1;
    }

    cout << cnt << endl;
    return 0;
}
