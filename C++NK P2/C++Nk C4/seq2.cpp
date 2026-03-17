#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("seq2.inp", "r", stdin);
    freopen("seq2.out", "w", stdout);
    long long n,k;
    vector<int> a = {1,3, 5, 7, 9, 11, 13, 33, 35, 55, 57, 77, 79, 99, 101, 103, 303, 305, 505, 507, 707, 709, 909, 911, 121, 123, 323, 325, 525, 527, 727, 729, 929, 931, 141, 143, 343, 345, 545, 547, 747, 749, 949, 951, 161, 163, 363, 365, 565, 567, 767, 769, 969, 971, 181, 183, 383, 385, 585, 587, 787, 789, 989, 991, 201, 104, 403, 306, 605, 508, 807, 710, 19, 93, 41, 16, 63, 38, 85, 60, 8, 10};
    while(cin>>n){
        // if(n==1){
        //     cout<<1<<"\n";
        //     continue;
        // }
        k = (n % a.size());
        if (k >= 1 && (k-1) < a.size()) {
            cout << a[k-1] << "\n";
        } else {
            continue;
        }
        // k = (n - 2) % a.size();
        // cout << a[k] << "\n";
    }
    return 0;
}