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

// Function to compare absolute values of two numbers
bool isSmaller(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size()) return v1.size() < v2.size();
    for (int i = v1.size() - 1; i >= 0; i--) {
        if (v1[i] != v2[i]) return v1[i] < v2[i];
    }
    return false;
}

string add(string s1, string s2) {
    bool neg1 = (s1[0] == '-');
    bool neg2 = (s2[0] == '-');

    // If both numbers are negative, add their absolute values and return a negative result
    if (neg1 && neg2) {
        vector<int> v1 = toVector(s1);
        vector<int> v2 = toVector(s2);
        vector<int> res;
        int carry = 0;

        for (int i = 0; i < max(v1.size(), v2.size()); i++) {
            int d1 = (i < v1.size()) ? v1[i] : 0;
            int d2 = (i < v2.size()) ? v2[i] : 0;
            int sum = d1 + d2 + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
        }
        if (carry) res.push_back(carry);

        string result = "-";
        for (int i = res.size() - 1; i >= 0; i--) result += (res[i] + '0');
        return result;
    }

    // If one number is negative, perform subtraction manually (without calling subtract function)
    if (neg1 || neg2) {
        string abs_s1 = neg1 ? s1.substr(1) : s1; // Remove '-' if negative
        string abs_s2 = neg2 ? s2.substr(1) : s2; // Remove '-' if negative
        vector<int> v1 = toVector(abs_s1);
        vector<int> v2 = toVector(abs_s2);

        bool resultNegative = false;
        if (isSmaller(v1, v2)) {
            swap(v1, v2);
            resultNegative = !neg1; // If s2 was negative, the result is positive, otherwise negative
        } else {
            resultNegative = neg1; // If s1 was negative, result is negative
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

        string result;
        if (resultNegative) result += '-';
        for (int i = res.size() - 1; i >= 0; i--) {
            result += (res[i] + '0');
        }
        return result;
    }

    // If both are positive, perform normal addition
    vector<int> v1 = toVector(s1);
    vector<int> v2 = toVector(s2);
    vector<int> res;
    int carry = 0;

    for (int i = 0; i < max(v1.size(), v2.size()); i++) {
        int d1 = (i < v1.size()) ? v1[i] : 0;
        int d2 = (i < v2.size()) ? v2[i] : 0;
        int sum = d1 + d2 + carry;
        carry = sum / 10;
        res.push_back(sum % 10);
    }
    if (carry) res.push_back(carry);

    // Convert result back to string
    string result;
    for (int i = res.size() - 1; i >= 0; i--) {
        result += (res[i] + '0');
    }
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << add(s1, s2) << endl;
}
