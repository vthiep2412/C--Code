#include <bits/stdc++.h>
using namespace std;
typedef long long ll; typedef unsigned long long ull; typedef long double ld; // number type
#define umap unordered_map
#define uset unordered_set
#define all(a) a.begin(), a.end()
#define pb emplace_back
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("bai3.inp", "r", stdin);
    //freopen("bai3.out", "w", stdout);
    int m,s;
    cin>>m>>s;
    int minI=9*m, maxI=9*m;
    bool validMin=true, validMax=true;
    if(minI<s){
        validMin=false;
    }
    if(maxI<s){
        validMax=false;
    }
    if(!validMin and !validMax){
        cout<<"-1 -1";
        return 0;
    }
    string minS, maxS;
    minS.resize(m, '9');
    maxS.resize(m, '9');
    //build min
    for(int i=m-1;i>=0;i--){
        int temp = 9;
        for(int j=9;j>=0;j--){
            if(i==0 and j==0) continue;
            if((minI-1)<s and minI>=s){
                break;
            }
            temp--;
            minS[i] = temp + '0';
            minI--;
        }
        if((minI-1)<s and minI>=s){
            break;
        }
    }
    // build max
    for(int i=0;i<m;i--){
        int temp = 9;
        for(int j=9;j>=0;j--){
            if(i==0 and j==0) continue;
            if((maxI-1)<s and maxI>=s){
                break;
            }
            temp--;
            maxS[i] = temp + '0';
            maxI--;
        }
        if((maxI-1)<s and maxI>=s){
            break;
        }
    }
    if(validMin){
        cout<<maxS<<" ";
    }
    if(validMax){
        cout<<minS;
    }else if (validMin and !validMax){
        cout<<"-1";
    }
    return 0;
}