#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
    ll Sereja=0,Dima=0;
    int n;
    bool flag=true;
    cin>>n; 
    vector<int> a(n);
    for(int &x:a) cin>>x;
    ll LEFT=0,RIGHT=n-1;
    while(LEFT<=RIGHT){
        if(flag){
            if(a[LEFT]>a[RIGHT]){
                Sereja+=a[LEFT];
                LEFT++;
            } else{
                Sereja+=a[RIGHT];
                RIGHT--;
            }
        }
        else{
            if(a[LEFT]>a[RIGHT]){
                Dima+=a[LEFT];
                LEFT++;
            } else{
                Dima+=a[RIGHT];
                RIGHT--;
            }
        }
        flag=!flag;
    }
    cout<<Sereja<<" "<<Dima<<"\n";
    return 0;
}