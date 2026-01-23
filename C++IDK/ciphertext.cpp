#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <ctime>

// A set of common words used for scoring.
const std::vector<std::string> COMMON_WORDS = {
    "the", "of", "and", "to", "a", "in", "was", "that", "he", "his", "is", "for", "with", "as", "not", "on"
};

// --- Helper Functions ---

// Decrypt the ciphertext using the current mapping.
// The mapping vector is 26 characters long, where mapping[0] is the plaintext letter for 'a', etc.
std::string decrypt(const std::string &ciphertext, const std::vector<char> &mapping) {
    std::string result;
    for (char c : ciphertext) {
        if (std::isalpha(c)) {
            bool upper = std::isupper(c);
            char lower = std::tolower(c);
            int idx = lower - 'a';
            char dec = mapping[idx];
            result.push_back(upper ? std::toupper(dec) : dec);
        } else {
            result.push_back(c);
        }
    }
    return result;
}

// Count occurrences of a substring within a string.
int countOccurrences(const std::string &text, const std::string &word) {
    int count = 0;
    size_t pos = text.find(word, 0);
    while (pos != std::string::npos) {
        // Check word boundaries:
        bool startOK = (pos == 0) || !std::isalpha(text[pos - 1]);
        bool endOK = (pos + word.size() >= text.size()) || !std::isalpha(text[pos + word.size()]);
        if (startOK && endOK) {
            count++;
        }
        pos = text.find(word, pos + 1);
    }
    return count;
}

// Score a decrypted text by counting occurrences of common words.
int scoreText(const std::string &plaintext) {
    int score = 0;
    std::string lowerPlain = plaintext;
    std::transform(lowerPlain.begin(), lowerPlain.end(), lowerPlain.begin(), ::tolower);
    for (const auto &word : COMMON_WORDS) {
        score += countOccurrences(lowerPlain, word);
    }
    return score;
}

// Generate an initial mapping based on frequency analysis.
// Uses a standard English frequency ordering.
std::vector<char> initialMapping(const std::string &ciphertext) {
    std::unordered_map<char, int> freq;
    for (char c : ciphertext) {
        if (std::isalpha(c)) {
            char lower = std::tolower(c);
            freq[lower]++;
        }
    }
    
    // Create a vector of (letter, frequency) pairs.
    std::vector<std::pair<char, int>> freqVec;
    for (char c = 'a'; c <= 'z'; c++) {
        freqVec.push_back({c, freq[c]});
    }
    
    // Sort letters descending by frequency.
    std::sort(freqVec.begin(), freqVec.end(), [](const auto &a, const auto &b) {
        return a.second > b.second;
    });
    
    // Standard English frequency order (most frequent to least frequent).
    std::string engFreq = "etaoinshrdlcumwfgypbvkjxqz";
    
    // Build an initial mapping array of 26 letters.
    std::vector<char> mapping(26, '?');
    for (size_t i = 0; i < freqVec.size(); i++) {
        int idx = freqVec[i].first - 'a';
        if (i < engFreq.size()) {
            mapping[idx] = engFreq[i];
        }
    }
    
    // For any letters not seen in ciphertext, assign remaining letters arbitrarily.
    std::vector<bool> used(26, false);
    for (char ch : mapping) {
        if (ch != '?')
            used[ch - 'a'] = true;
    }
    int pos = 0;
    for (int i = 0; i < 26; i++) {
        if (mapping[i] == '?') {
            while (pos < 26 && used[pos]) pos++;
            if (pos < 26) {
                mapping[i] = 'a' + pos;
                used[pos] = true;
            }
        }
    }
    
    return mapping;
}

// Print the mapping (cipher letter -> plaintext letter) in alphabetical order.
void printMapping(const std::vector<char> &mapping) {
    std::cout << "Mapping (cipher -> plaintext):\n";
    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>('a' + i) << " -> " << mapping[i] << "\n";
    }
    std::cout << std::endl;
}

// --- Main Hill Climbing Algorithm ---
int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // The ciphertext to solve.
    std::string ciphertext = "hzsrnqc klyy wqc flo mflwf ol zqdn nsoznj wskn lj xzsrbjnf, wzsxz gqv zqhhnf ol ozn glco zlfnco hnlhrn; nsoznj jnrqosdnc lj fnqj kjsnfbc, wzsxz sc xnjoqsfrv gljn efeceqr. zn rsdnb qrlfn sf zsc zlecn sf cqdsrrn jlw, wzsoznj flfn hnfnojqonb. q csfyrn blgncosx cekksxnb ol cnjdn zsg. zn pjnqmkqconb qfb bsfnb qo ozn xrep, qo zlejc gqozngqosxqrrv ksanb, sf ozn cqgn jllg, qo ozn cqgn oqprn, fndnj oqmsfy zsc gnqrc wsoz loznj gngpnjc, gexz rncc pjsfysfy q yenco wsoz zsg; qfb wnfo zlgn qo naqxorv gsbfsyzo, lfrv ol jnosjn qo lfxn ol pnb. zn fndnj ecnb ozn xlcv xzqgpnjc wzsxz ozn jnkljg hjldsbnc klj soc kqdlejnb gngpnjc. zn hqccnb onf zlejc leo lk ozn ownfov-klej sf cqdsrrn jlw, nsoznj sf crnnhsfy lj gqmsfy zsc olsrno.";
    
    // Create an initial mapping based on frequency analysis.
    std::vector<char> currentMapping = initialMapping(ciphertext);
    std::string currentDecryption = decrypt(ciphertext, currentMapping);
    int currentScore = scoreText(currentDecryption);
    
    std::cout << "Initial decryption:\n" << currentDecryption << "\n";
    std::cout << "Initial score: " << currentScore << "\n\n";
    
    // Hill climbing parameters.
    int iterations = 100000;
    std::vector<char> bestMapping = currentMapping;
    std::string bestDecryption = currentDecryption;
    int bestScore = currentScore;
    
    // Hill climbing loop.
    for (int iter = 0; iter < iterations; iter++) {
        // Copy current mapping and swap two random positions.
        std::vector<char> newMapping = currentMapping;
        int i = std::rand() % 26;
        int j = std::rand() % 26;
        while (j == i)
            j = std::rand() % 26;
        std::swap(newMapping[i], newMapping[j]);
        
        std::string newDecryption = decrypt(ciphertext, newMapping);
        int newScore = scoreText(newDecryption);
        
        // If the new mapping produces a better score, adopt it.
        if (newScore > currentScore) {
            currentMapping = newMapping;
            currentDecryption = newDecryption;
            currentScore = newScore;
            
            if (currentScore > bestScore) {
                bestMapping = currentMapping;
                bestDecryption = currentDecryption;
                bestScore = currentScore;
            }
        }
    }
    
    // Output the best result found.
    std::cout << "Best decryption after hill climbing:\n" << bestDecryption << "\n\n";
    printMapping(bestMapping);
    std::cout << "Best score: " << bestScore << "\n";
    
    return 0;
}
