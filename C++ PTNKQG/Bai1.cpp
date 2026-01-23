#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main() {
    int n;
    cin >> n;

    auto start = high_resolution_clock::now();

    int a[n];
    int aSize = sizeof(a) / sizeof(a[0]);
    for (int j = 1; j <= n; j++) {
        a[j-1] = j;      
    }
    while (aSize > 1) {
        int newSize = 0;

        for (int i = 0; i < aSize; i++) {
            if ((i + 1) % 3 == 2) {
                a[newSize] = a[i];
                newSize++;
            }
        }

        aSize = newSize;    
        for (int f = 0; f < aSize;f++) {
        cout << a[f] << " ";
        }
        cout << endl;
    }
    cout << a[0];


    auto stop = high_resolution_clock::now(); // Stop time
    duration<double> duration = stop - start;
    cout << "\nTime taken by function: " << duration.count() << " seconds" << endl;
    return 0;



}
