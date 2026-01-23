#include <bits/stdc++.h>
using namespace std;

bool issuperprimes(int n, vector<bool>& isPrime) {
    int temp = n;
    while (temp > 0) {
        if (!isPrime[temp]) return false;
        temp /= 10;
    }
    return true;
}

// Function to compute all primes up to sqrt(n) using simple sieve
vector<bool> simpleSieve(int limit) {
    vector<bool> mark(limit + 1, true);
    mark[0] = mark[1] = false;
    for (int p = 2; p * p <= limit; p++) {
        if (mark[p]) {
            for (int i = p * p; i <= limit; i += p)
                mark[i] = false;
                cout<<"DEBUG: Marked non-prime for p="<<p<<"\n";
        }
    }
    return mark;
}
// Usage example
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    int N = pow(10, n-1);  // Use built-in pow function
    std::cout << "DEBUG: n=" << n << ", N=" << N << std::endl;
    vector<bool> isPrime = simpleSieve(N*10-1);  // Corrected sieve limit
    std::cout << "DEBUG: Sieve created up to " << N*10-1 << std::endl;
    for (int i = N; i <= N*10-1; i++) {
        if (isPrime[i]) {
            // std::cout << "DEBUG: Checking superprime for " << i << std::endl;
            if (issuperprimes(i, isPrime)) {
                std::cout<<"Founddddddddddddddddddddddddddddddddddddddddddddd  "<<i<<"\n";
            }
        }
    }
    return 0;
}