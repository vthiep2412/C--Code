#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    string str;
    cin>>str;
    cout << str << endl;

    reverse(str.begin(), str.end());

    cout << str << endl;

    return 0;
}