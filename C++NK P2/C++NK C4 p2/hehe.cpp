#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (!freopen("cache.txt", "w", stdout)) {
        cerr << "Failed to redirect stdout\n";
        return 1;
    }

    const size_t chunkSize = 1024 * 1024;
    const size_t totalSize = 5LL * 1024 * 1024 * 1024;
    const size_t iterations = totalSize / chunkSize;

    string chunk(chunkSize, 'A');

    for (size_t i = 0; i < iterations; ++i) {
        cout.write(chunk.c_str(), chunkSize);
    }
    cerr << "\nFinished writing 5 GB to cache.txt\n";
    return 0;
}