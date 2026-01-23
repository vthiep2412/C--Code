#include <bits/stdc++.h>
using namespace std;

pair<int, int> solve(int n) {
    int cnt=0, max=0, a=0, b=0;
    while (n>0){   
        a=n%10;
        n=n/10;
        if (a>=b){
            if (a>b){
                b=a;
                cnt=1;
            }
            else{cnt++;}
        }
    }
    return {b, cnt};
}

int main() {
    int n;
    cin >> n;
    auto ketqua = solve(n);
    cout << ketqua.first << " " << ketqua.second;
    return 0;
}