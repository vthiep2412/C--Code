#include <bits/stdc++.h>
using namespace std;

bool kt(int n){
    if(n < 2) return false;
    if(n == 2 || n == 3 || n == 5) return true;
    if(n % 2 == 0 || n % 3 == 0 || n % 5 == 0) return false;    
    const int c2 = sqrt(n);
    for(int i = 7; i <= c2; i += 2){
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k;
    cin >> n;
    k = n;
    int start = (n % 2 == 0) ? n + 1 : n;
    int previousPrime = -1;
    for (int i = start; i <= n * n * n; i += 2) {
        if (kt(i)) {
            if (previousPrime != -1 && i - previousPrime >= k) {
                cout << previousPrime << " " << i;
                return 0;
            }
            previousPrime = i;
        }
    }
    
    return 0;
}

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n;
//     cin >> n;
//     int m=n;
//     vector<int> a;
//     if(n % 2 == 0) n++;
//     for(int i = n; i <= n*n*n; i+=2){
//         if(kt(i)) a.push_back(i);
//     }
//     for(size_t i = 0; i < a.size()-1; i++){
//         if(a[i+1] - a[i] >= m){
//             cout << a[i] << " " << a[i+1];
//             return 0;
//         }
//     }
//     cout<<"not found";
//     return 0;
// }