#include <bits/stdc++.h>
using namespace std;

int main() {
    auto start = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    const int c = 14;
    int cnt = 0;
    vector<int> a = {9,8,8,4,6};

    sort(a.begin(), a.end(), greater<int>());

    while (!a.empty()) {
        int n = 0;
        for (int i = 0; i < a.size(); ) {
            if (n + a[i] <= c) {
                n += a[i];
                a.erase(a.begin() + i);
            } else {
                i++;
            }
        }
        cout<<n<<"\n";
        cnt++;
    }

    cout << cnt;

    auto end = chrono::high_resolution_clock::now(); 
    chrono::duration<double> duration = end - start;
    cout << "\nExecution time: " << duration.count() << " s" << endl;
    return 0;
}