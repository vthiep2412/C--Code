#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, M;
    cin >> N;
    deque<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a.push_back(9);
    cout << a.front()<<"\n";
    
    return 0;
}
