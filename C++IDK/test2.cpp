#include <iostream>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Optimized trial division: checks divisibility by 2, 3, and then 6k ± 1
bool isPrimeTD(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;  // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return false;

    long long limit = static_cast<long long>(sqrt(n));
    for (long long i = 5; i <= limit; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long N;
    cin >> N;  // Read input

    // Start timing after input
    auto start = high_resolution_clock::now();

    // Check every number from 2 to N
    for (long long i = 2; i <= N; i++) {
        if (isPrimeTD(i)) {
            cout << i << "\n";
        }
    }

    // End timing
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}
