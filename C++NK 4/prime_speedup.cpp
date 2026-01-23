#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool kt(int num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i+=2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

bool check(int num)
{
    if (num < 2)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;
    for (int i = 3; i <= sqrt(num); i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

vector<int> printPrime(int n)
{
    vector<int> primes;
    if (n >= 2) primes.push_back(2);
    for (int i = 3; i <= n; i+=2)
    {
        if (kt(i))
            primes.push_back(i);
    }
    return primes;
}

bool checkPrime(vector<int> n)
{
    int cnt = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if (!check(n[i]))
            cnt++;
    }
    if (cnt == 0)
        return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < printPrime(n).size(); i++)
    {
        cout << printPrime(n)[i] << " ";
    }

    if(checkPrime(printPrime(n))){
        cout << "YES";
    } else {
        cout << "NO";
    }
    return 0;
}