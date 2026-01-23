#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("TBC.INP", "r", stdin);
    freopen("TBC.OUT", "w", stdout);
    int n;
    double tbc;
    cin >> n;
    pair<string, double> maxi{"", INT_MIN};
    
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        int sum = 0, cnt = 0;
        for(int j = 0; j < str.size(); j++){
            if(isdigit(str[j])){
                sum += str[j] - '0';
                cnt++;
            }
        }
        if (cnt > 0) {
            tbc = sum / cnt;
            if(maxi.second < tbc){
                maxi = {str, tbc};
            }
        }
    }
    cout << maxi.first;
    return 0;
}
