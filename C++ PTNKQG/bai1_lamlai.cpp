#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int main() {
    int n,cnt=0;
    cin >> n;

    auto start = high_resolution_clock::now();
    vector<int> b;
    vector<int> a(n);
    for (int j = 1; j <= n; j++) {
        a[j-1] = j;      
    }
    while (a.size() > 1) {
        b.clear();
        for(int i=1;i<=a.size();i++)
        {
            if((i)%3==2)
            {
                b.push_back(a[i-1]);
            }
        }
        a=b;


    }
    cout << a[0];


    auto stop = high_resolution_clock::now(); // Stop time
    duration<double> duration = stop - start;
    cout << "\nTime taken by function: " << duration.count() << " seconds" << endl;
    return 0;



}
