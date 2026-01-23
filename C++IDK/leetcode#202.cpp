#include <bits/stdc++.h>
using namespace std;

bool isHappy(int n) {
    unordered_set<int> seen;
    int sum = n, tempsum = 0;
    while(sum != 1 && seen.find(sum) == seen.end()){
        seen.insert(sum);
        while(sum != 0) {
            tempsum += (sum % 10) * (sum % 10);
            sum /= 10;
        }
        sum = tempsum;
        tempsum = 0;
    }
    return sum == 1;
}


int main(){
    int n;
    cin >> n;
    cout << isHappy(n);
}