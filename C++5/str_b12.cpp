#include <bits/stdc++.h>
using namespace std;

vector<int> toVector(string s) {
    vector<int> v;
    bool isNegative = (s[0] == '-'); 
    for (int i = s.size() - 1; i >= isNegative; i--) { // Skip '-' sign if negative
        v.push_back(s[i] - '0');
    }
    return v;
}

// Function to compare two absolute values
bool isSmaller(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size()) return v1.size() < v2.size();
    for (int i = v1.size() - 1; i >= 0; i--) {
        if (v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return false;
}

string subtract(string s1, string s2) {
    bool neg1 = (s1[0] == '-');
    bool neg2 = (s2[0] == '-');
    bool resultNegative = false;

    vector<int> v1 = toVector(s1);
    vector<int> v2 = toVector(s2);
    
    if (neg1 && neg2) {
        // If both are negative, swap and subtract normally
        swap(v1, v2);
        resultNegative = isSmaller(v1, v2);
    } else if (neg1) {
        // If s1 is negative and s2 is positive, return -(abs(s1) + abs(s2))
        vector<int> sum;
        int carry = 0;
        int maxSize = max(v1.size(), v2.size());

        for (int i = 0; i < maxSize; i++) {
            int d1 = (i < v1.size()) ? v1[i] : 0;
            int d2 = (i < v2.size()) ? v2[i] : 0;
            int sumDigit = d1 + d2 + carry;
            carry = sumDigit / 10;
            sum.push_back(sumDigit % 10);
        }
        if (carry) sum.push_back(carry);

        string result = "-";
        for (int i = sum.size() - 1; i >= 0; i--) result += (sum[i] + '0');
        return result;
    } else if (neg2) {
        // If s1 is positive and s2 is negative, return s1 + abs(s2)
        vector<int> sum;
        int carry = 0;
        int maxSize = max(v1.size(), v2.size());

        for (int i = 0; i < maxSize; i++) {
            int d1 = (i < v1.size()) ? v1[i] : 0;
            int d2 = (i < v2.size()) ? v2[i] : 0;
            int sumDigit = d1 + d2 + carry;
            carry = sumDigit / 10;
            sum.push_back(sumDigit % 10);
        }
        if (carry) sum.push_back(carry);

        string result;
        for (int i = sum.size() - 1; i >= 0; i--) result += (sum[i] + '0');
        return result;
    }

    // Determine which is larger to subtract properly
    if (isSmaller(v1, v2)) {
        swap(v1, v2);
        resultNegative = true;
    }

    vector<int> res;
    int borrow = 0;

    for (int i = 0; i < v1.size(); i++) {
        int d1 = v1[i];
        int d2 = (i < v2.size()) ? v2[i] : 0;

        int diff = d1 - d2 - borrow;
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        res.push_back(diff);
    }

    // Remove leading zeros
    while (res.size() > 1 && res.back() == 0) {
        res.pop_back();
    }

    // Convert result back to string
    string result;
    if (resultNegative) result += '-';
    for (int i = res.size() - 1; i >= 0; i--) {
        result += (res[i] + '0');
    }

    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << subtract(s1, s2) << endl;
}
