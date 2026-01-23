#include <gmpxx.h>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>      // for std::ceil and log2
#include <cstdint>    // for uint64_t

using std::cout;
using std::endl;
using std::string;
using std::to_string;
using std::vector;

// Compute π with the Chudnovsky series
void pi_chudnovsky(std::size_t terms, std::size_t precision) {
    // Convert decimal digits to bits (with a small guard)
    long bits = static_cast<long>(std::ceil((precision + 10) * std::log2(10.0)));
    mpf_set_default_prec(bits);

    // Precompute the constant C = 426880 * sqrt(10005)
    mpf_class C = mpf_class(426880) * sqrt(mpf_class(10005));

    // Initialize series variables
    mpf_class M = 1;
    mpf_class L = 13591409;
    mpf_class X = 1;
    mpf_class S = L;
    uint64_t K = 6;

    vector<string> result;
    std::size_t step_interval = std::max<std::size_t>(1, terms / 10);

    // Main loop: assemble series
    for (std::size_t k = 1; k < terms; ++k) {
        // Recurrence updates
        mpf_class numeratorM = M * (mpf_class(K*K*K) - mpf_class(16) * K);
        mpf_class denominatorM = mpf_class(k) * k * k;
        M = numeratorM / denominatorM;

        L += 545140134;
        X *= mpf_class(-262537412640768000LL);
        S += M * L / X;

        // Every ~terms/10, record an intermediate π
        if (k % step_interval == 0) {
            mpf_class pi_approx = C / S;
            // get_str(count, base) → string with 'count' significant digits
            string digits = pi_approx.get_str(precision + 1, 10);
            result.push_back("Step " + to_string(k) +
                             ": π ≈ " + digits);
        }

        K += 12;
    }

    // Final approximation
    mpf_class pi_final = C / S;
    string final_digits = pi_final.get_str(precision + 1, 10);
    result.push_back("\nFinal π ≈ " + final_digits);

    // Print all results
    for (auto &line : result) {
        cout << line << "\n";
    }
}

int main() {
    // Example: 1,000 terms, 100,000-digit precision
    std::size_t terms = 1000;
    std::size_t precision = 100000;
    pi_chudnovsky(terms, precision);
    return 0;
}
