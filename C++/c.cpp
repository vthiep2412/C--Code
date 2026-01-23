#include <iostream>
#include <cmath>
using namespace std;

bool kt(int num)
{
    if(num > 1){
        for (int i = 2; i <= sqrt(num); i++) { // Corrected loop condition
            if (num % i == 0) {
                return false;
            }
        }
    }
    return true;
}

bool kts(int n)
{
    while (n > 0) {
        if (!kt(n)) { // Check if the number is prime
            return false;
        }
        n /= 10; // Remove the last digit
    }
    return true;
}

int main()
{
    int input, input2;
    cin >> input;
    cin >> input2;
    for (int i = input; i <= input2; i++)
    {
        if (kts(i)) // Simplified condition check
        {
            cout << i << " ";
        }
    }

    return 0;
}