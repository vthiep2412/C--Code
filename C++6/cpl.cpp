#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a;
    cin >> a;
    int x = sqrt(a);
    int cnt = 0, sum = 0;
    for(int i = 1; i <= x; i++){
        if((i*i)%2!=0){
            cnt++;
            sum += i*i;
        }
    }
    cout << cnt << "\n" << sum;
}