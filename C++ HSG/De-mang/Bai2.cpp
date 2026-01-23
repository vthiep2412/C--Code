#include <bits/stdc++.h>
using namespace std;
// cách 1 có khả năng chậm hơn nhưng space complexity o(n)
// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int n,cnt=0;
//     cin >> n;
//     vector<int> a(n);
//     unordered_map<int, int> mp;
//     for(int i = 0; i < n; i++){
//         cin >> a[i];
//         mp[a[i]]++;
//     }
//     int mini = INT_MAX;
//     for(auto x : mp){
//         if(x.first < mini && x.second > 1){
//             mini = x.first;
//             cnt = x.second;
//         }
//     }

//     if(cnt==n){
//         cout<<mini<<" "<<cnt;
//         return 0;
//     }
//     cout << mini << " " << n-cnt;
//     return 0;
// }

// cách 2 có khả năng nhanh hơn nhưng space complexity o(1)
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,cnt=1,min=INT_MAX;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        if(x < min){
            min = x;
            cnt = 1;
        }
        else if(x == min) cnt++;
    }
    if(cnt==n){
        cout<<min<<" "<<cnt;
        return 0; 
    }
    cout << min << " " << n-cnt;
    return 0;
}