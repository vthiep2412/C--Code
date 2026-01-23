#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    long k;
    int cnt_minus=0;
    cin >> k;
    auto start = chrono::high_resolution_clock::now(); 

    for(long i = 1; i <= k; i++){
        s.append(to_string(i));
        s.append(to_string(i+1));
        s.append(to_string(i+2));
        if (s.find(to_string(k)) != string::npos) {
            cout << s.find(to_string(k))+cnt_minus+1;

            auto end = chrono::high_resolution_clock::now(); 
            chrono::duration<double> duration = end - start;
            cout << "\nExecution time: " << duration.count() << " s" << endl;

            return 0;
        }
        else{
            s.erase(0, 1);
            cnt_minus++;
        }
    }
}