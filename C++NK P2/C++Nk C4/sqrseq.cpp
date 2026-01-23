#include <bits/stdc++.h>
using namespace std;

bool check(long long n){
    if(n<1) return false;
    long long oi = sqrt(n);
    if(oi*oi==n) return true;
    return false; 
}

int main() {
    long long n=9;
    vector<long long> v={3,0,1,9,4,6,25,9,9};
    vector<long long> temp;
    pair<long long,long long> oitemp;
    vector<long long> res;
    pair<long long,long long> oires = {-1,-1};
    for(long long i=0;i<n;i++){
        cin >> v[i];
    }
    for(long long i=0;i<v.size();i++){
        if(check(v[i])){
            temp.push_back(v[i]);
            if(temp.size() == 1){
                oitemp.first = i;
            } else{
                oitemp.second = i;
            }
        }else{
            if(temp.size()>res.size()){
                if(oires.first == -1){
                    oires = oitemp;
                    res = temp;
                    temp.clear();
                }
            }
        }
    }
    if(temp.size()>res.size()){
        if(oires.first == -1){
            oires = oitemp;
            res = temp;
            temp.clear();
        }
    }
    cout<<"\n"<<oires.first+1<<" "<<oires.second+1;
    return 0;
}