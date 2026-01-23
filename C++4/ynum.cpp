#include <bits/stdc++.h>
#include <chrono>
using namespace std;

int main(){

    string s;
    long k;
    cin >> k;

    auto start = chrono::high_resolution_clock::now(); 

    for(long i = 1; i <= k; i++){
        s.append(to_string(i));
        s.append(to_string(i+1));
        s.append(to_string(i+2));
    }
    
    for(long i = 0; i < s.size(); i++){
        if(s.substr(i, to_string(k).size()) == to_string(k)){
            cout << i+1;
     
            auto end = chrono::high_resolution_clock::now(); 
            chrono::duration<double> duration = end - start;
            cout << "\nExecution time: " << duration.count() << " s" << endl;

     
            return 0;
        }
    }
}