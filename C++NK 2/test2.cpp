#include <iostream>

using namespace std;

int main() {
    int n, T;
    int tong = 0;

    cin >> n >> T;

    int arr[n]; 
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int i =0;
    int dem = 0;
    while(i<n)
    {
        tong = 0;
        for (int j = i; j < n ; j++) {
            tong = tong + arr[j];
            // cout<<"tong: "<<tong<<endl;
            if(tong == T) {
                dem++;
                i = j + 1;
                break;
            }
        }
        if(tong !=T) i=i+1;
    }
   
    cout << dem << "\n";

    return 0;
}