#include <iostream>
using namespace std;

int Atm(int a, int b, int c) {
    int cnt = 0;
    for(int i=0;i<=c;i++){
        for(int j=0;j<=b;j++){
            for(int k=0;k<=a;k++){
                if(20*i+10*j+5*k==c){
                    cnt++;
                }
            }
        } 
    }
}