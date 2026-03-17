#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);

    long long N;
    cin >> N;  // Read input

    // Start timing after input
    auto start = high_resolution_clock::now();

    // Create the sieve array
    vector<bool> sieve(N + 1, true);
    if (N >= 0) sieve[0] = false;
    if (N >= 1) sieve[1] = false;

    // We only need to mark multiples up to sqrt(N)
    long long limit = static_cast<long long>(sqrt(N));

    // Single pass: check and mark
    for (long long i = 2; i <= N; i++) {
        if (sieve[i]) {
            // i is prime — print it immediately
            cout << i << "\n";

            // Mark multiples of i if i <= limit
            if (i <= limit) {
                for (long long j = i * i; j <= N; j += i) {
                    sieve[j] = false;
                }
            }
        }
    }

    // End timing
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken: " << duration.count() << " ms\n";

    return 0;
}
