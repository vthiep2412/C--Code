// idk time complexity
/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    long long n;
    cin>>n;
    int cnt=__builtin_popcountll(N);;
    int logi = (log2(n));
    cout<<cnt+logi;
    return 0;
}
*/
// still o(log n)
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen(".inp", "r", stdin);
    // freopen(".out", "w", stdout);
    int cnt=0;
    long long n;
    cin>>n;
    while(n!=0){
        if(n%2==0){
            n/=2;
            cnt++;
        }
        else{
            n--;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}