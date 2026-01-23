#include <iostream>
#include <chrono>
#include <sstream>

using namespace std;

int main() {
    int limit = 1000000;

    // Disable synchronization for faster I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Start timer
    auto start = chrono::high_resolution_clock::now();

    // Use stringstream to accumulate results
    stringstream output;
    for (int i = 0; i < limit; i++) {
        output << i << '\n';
    }

    // Output everything at once
    cout << output.str();

    // End timer
    auto end = chrono::high_resolution_clock::now();

    // Calculate elapsed time in seconds
    auto elapsed = chrono::duration_cast<chrono::seconds>(end - start);

    cout << "Total time: " << elapsed.count() << " seconds" << endl;

    return 0;
}
