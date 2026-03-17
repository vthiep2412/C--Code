#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3 || n == 5) return true;
    if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;
    const long long c2 = sqrt(n);
    for (long long i = 7; i <= c2; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isSophieGermainPrime(long long n) {
    return isPrime(n) && isPrime(2 * n + 1);
}

void checkSophieGermainPrimes(long long n) {
    int cnt = 0;
    for (long long i = 1; i <= n; i++) {
        if (isSophieGermainPrime(i)) {
            cout << i << " yes" << "\n";
            cnt++;
        } else {
            cout << i << " no" << "\n";
        }
    }
    cout << "Total Sophie Germain Prime Number: " << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    long long n;
    cout << "Enter the value of n: ";
    cin >> n;
    checkSophieGermainPrimes(n);
    return 0;
}
