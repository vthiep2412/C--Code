#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool kt(int num)
{
    if (num < 2) return false;
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0) return false;
    }
    return true;
}

int main()
{
    int n=0,cnt=0;
    cin >> n;
    if(2<=n && n<=100){}
    else {return 0;}
    vector<int> a(n);
    int c = a.size();
    for (int i = 0; i < c; i++)
    {
        cin>>a[i];
    }
    for( int i=0;i<c;i++)
    {
        if(kt(a[i])){
            cnt++;
        }
    }
    if(cnt==0){
        cout<<0;
        return 0;
        }
    for(int j=0;j < c; j++)
    {
        if(kt(a[c-1]))
        {
            cout << a[c-2];
        }
        else if(kt(a[j]))
        {
            cout<<a[j+1]<<" ";
        }
    }

}
