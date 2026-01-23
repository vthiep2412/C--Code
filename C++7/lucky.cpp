#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    long long K;
    cin >> N >> K;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    unordered_map<long long, int> countMap;
    long long count = 0;

    for (int i = 0; i < N; i++) {
        long long complement1 = K - a[i];
        long long complement2 = -K - a[i];

        if (countMap.find(complement1) != countMap.end()) {
            count += countMap[complement1];
        }
        if (countMap.find(complement2) != countMap.end()) {
            count += countMap[complement2];
        }

        countMap[a[i]]++;
    }

    cout << count << "\n";

    return 0;
}