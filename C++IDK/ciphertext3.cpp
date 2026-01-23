#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <regex>
#include <sstream>

class EnhancedSubstitutionAnalyzer {
private:
    // English letter frequencies (more detailed)
    const std::string eng_frequencies = "etaoinshrdlcumwfgypbvkjxqz";
    
    // Common English bigrams
    const std::vector<std::string> common_bigrams = {
        "th", "he", "in", "er", "an", "re", "nd", "at", "on", "nt",
        "ha", "es", "st", "en", "ed", "to", "it", "ou", "ea", "hi"
    };

    // Common English trigrams
    const std::vector<std::string> common_trigrams = {
        "the", "and", "ing", "her", "hat", "his", "tha", "ere",
        "for", "ent", "ion", "ter", "was", "you", "ith", "ver"
    };

    // Common word endings
    const std::vector<std::string> common_endings = {
        "ing", "ed", "tion", "ly", "ment", "ers", "est", "able"
    };

    // Common word beginnings
    const std::vector<std::string> common_beginnings = {
        "th", "wh", "sh", "ch", "ph", "qu", "tr", "br", "fr", "gr"
    };

    // Single letter words in English
    const std::set<char> single_letters = {'a', 'i'};

    struct NGramAnalysis {
        std::map<std::string, int> frequencies;
        double score;
    };

    // Helper function for N-gram analysis
    NGramAnalysis analyzeNGrams(const std::string& text, int n) {
        NGramAnalysis result;
        std::string lower_text = toLower(text);
        
        for (size_t i = 0; i <= lower_text.length() - n; i++) {
            std::string ngram = lower_text.substr(i, n);
            if (std::all_of(ngram.begin(), ngram.end(), ::isalpha)) {
                result.frequencies[ngram]++;
            }
        }
        
        // Calculate score based on common n-grams
        result.score = 0;
        const auto& common_ngrams = (n == 2) ? common_bigrams : common_trigrams;
        for (const auto& common : common_ngrams) {
            if (result.frequencies.find(toLower(common)) != result.frequencies.end()) {
                result.score += result.frequencies[toLower(common)];
            }
        }
        
        return result;
    }

    // Analyze word boundaries
    struct WordBoundaryAnalysis {
        std::map<char, int> word_starts;
        std::map<std::string, int> word_ends;
        std::vector<std::string> single_letter_words;
    };

    WordBoundaryAnalysis analyzeWordBoundaries(const std::string& text) {
        WordBoundaryAnalysis result;
        std::istringstream iss(text);
        std::string word;

        while (iss >> word) {
            if (!word.empty() && std::isalpha(word[0])) {
                result.word_starts[std::tolower(word[0])]++;
            }
            
            if (word.length() >= 2) {
                result.word_ends[word.substr(word.length() - 2)]++;
            }
            
            if (word.length() == 1 && std::isalpha(word[0])) {
                result.single_letter_words.push_back(toLower(word));
            }
        }
        
        return result;
    }

    // Vowel pattern analysis
    struct VowelAnalysis {
        std::map<char, double> vowel_likelihood;
        std::vector<char> likely_vowels;
    };

    VowelAnalysis analyzeVowelPatterns(const std::string& text) {
        VowelAnalysis result;
        std::string lower_text = toLower(text);
        
        // Calculate likelihood of each letter being a vowel based on patterns
        for (char c = 'a'; c <= 'z'; c++) {
            double score = 0;
            int count = 0;
            
            for (size_t i = 0; i < lower_text.length(); i++) {
                if (lower_text[i] == c) {
                    count++;
                    // Check surrounding letters
                    if (i > 0 && i < lower_text.length() - 1) {
                        char prev = lower_text[i-1];
                        char next = lower_text[i+1];
                        if (std::isalpha(prev) && std::isalpha(next)) {
                            score += 0.5; // Likely vowel if between consonants
                        }
                    }
                }
            }
            
            if (count > 0) {
                result.vowel_likelihood[c] = score / count;
                if (score / count > 0.4) { // Threshold for vowel likelihood
                    result.likely_vowels.push_back(c);
                }
            }
        }
        
        return result;
    }

    // Convert string to lowercase
    std::string toLower(std::string str) {
        std::transform(str.begin(), str.end(), str.begin(), ::tolower);
        return str;
    }

public:
    struct EnhancedAnalysisResult {
        std::map<char, char> mapping;
        std::string sample_decryption;
        double confidence_score;
        std::vector<std::string> possible_words;
    };

    EnhancedAnalysisResult analyzeText(const std::string& ciphertext) {
        EnhancedAnalysisResult result;
        std::string lower_text = toLower(ciphertext);

        // 1. Basic frequency analysis
        auto char_freq = analyzeCharacterFrequencies(lower_text);
        
        // 2. N-gram analysis
        auto bigram_analysis = analyzeNGrams(lower_text, 2);
        auto trigram_analysis = analyzeNGrams(lower_text, 3);
        
        // 3. Word boundary analysis
        auto word_analysis = analyzeWordBoundaries(lower_text);
        
        // 4. Vowel pattern analysis
        auto vowel_analysis = analyzeVowelPatterns(lower_text);

        // 5. Create initial mapping based on combined analysis
        createInitialMapping(result.mapping, char_freq, bigram_analysis, 
                           word_analysis, vowel_analysis);

        // 6. Refine mapping using pattern rules
        refineMapping(result.mapping, lower_text, bigram_analysis, 
                     trigram_analysis, word_analysis);

        // 7. Calculate confidence score
        result.confidence_score = calculateConfidenceScore(result.mapping, 
                                                         bigram_analysis, 
                                                         trigram_analysis);

        // 8. Generate sample decryption
        result.sample_decryption = decrypt(ciphertext, result.mapping);

        // 9. Find possible words in decrypted text
        findPossibleWords(result.sample_decryption, result.possible_words);

        return result;
    }

    std::map<char, int> analyzeCharacterFrequencies(const std::string& text) {
        std::map<char, int> freq;
        for (char c : text) {
            if (std::isalpha(c)) {
                freq[std::tolower(c)]++;
            }
        }
        return freq;
    }

    void createInitialMapping(std::map<char, char>& mapping,
                            const std::map<char, int>& char_freq,
                            const NGramAnalysis& bigram_analysis,
                            const WordBoundaryAnalysis& word_analysis,
                            const VowelAnalysis& vowel_analysis) {
        // Implementation of initial mapping creation
        std::vector<std::pair<char, int>> freq_vec(char_freq.begin(), char_freq.end());
        std::sort(freq_vec.begin(), freq_vec.end(),
                 [](const auto& a, const auto& b) { return a.second > b.second; });

        // Map most frequent letters first
        for (size_t i = 0; i < freq_vec.size() && i < eng_frequencies.length(); i++) {
            mapping[freq_vec[i].first] = eng_frequencies[i];
        }

        // Adjust for single letter words
        for (const auto& single : word_analysis.single_letter_words) {
            if (single_letters.find('a') != single_letters.end()) {
                mapping[single[0]] = 'a';
            }
        }

        // Adjust for likely vowels
        for (char vowel : vowel_analysis.likely_vowels) {
            if (mapping.find(vowel) == mapping.end()) {
                // Map to most likely unused vowel
                for (char v : {'e', 'a', 'i', 'o', 'u'}) {
                    bool used = false;
                    for (const auto& m : mapping) {
                        if (m.second == v) {
                            used = true;
                            break;
                        }
                    }
                    if (!used) {
                        mapping[vowel] = v;
                        break;
                    }
                }
            }
        }
    }

    void refineMapping(std::map<char, char>& mapping,
                      const std::string& text,
                      const NGramAnalysis& bigram_analysis,
                      const NGramAnalysis& trigram_analysis,
                      const WordBoundaryAnalysis& word_analysis) {
        // Implementation of mapping refinement
        bool changed;
        do {
            changed = false;
            
            // Check for common word patterns
            std::istringstream iss(text);
            std::string word;
            while (iss >> word) {
                if (word.length() == 3) {
                    // Check for "the" pattern
                    if (word[0] == word[2]) {
                        mapping[word[0]] = 't';
                        mapping[word[1]] = 'h';
                        mapping[word[2]] = 'e';
                        changed = true;
                    }
                }
            }

            // Apply other refinement rules...

        } while (changed);
    }

    double calculateConfidenceScore(const std::map<char, char>& mapping,
                                  const NGramAnalysis& bigram_analysis,
                                  const NGramAnalysis& trigram_analysis) {
        // Implementation of confidence score calculation
        double score = 0.0;
        
        // Add scores based on different factors
        score += bigram_analysis.score * 0.3;
        score += trigram_analysis.score * 0.4;
        
        // Normalize score to 0-1 range
        return std::min(1.0, score / 100.0);
    }

    void findPossibleWords(const std::string& text,
                          std::vector<std::string>& possible_words) {
        // Implementation of word finding
        std::istringstream iss(text);
        std::string word;
        while (iss >> word) {
            if (word.length() >= 3) {
                possible_words.push_back(word);
            }
        }
    }

    std::string decrypt(const std::string& text,
                       const std::map<char, char>& mapping) {
        std::string result;
        for (char c : text) {
            if (std::isalpha(c)) {
                char lc = std::tolower(c);
                if (mapping.find(lc) != mapping.end()) {
                    result += std::isupper(c) ? 
                             std::toupper(mapping.at(lc)) : mapping.at(lc);
                } else {
                    result += c;
                }
            } else {
                result += c;
            }
        }
        return result;
    }
};

int main() {
    std::string ciphertext = "ltadehr mopp chr ion vioci no thge eantes came os utadbsei, "
                            "ctaut why thllei no nte worn toiern leol";

    EnhancedSubstitutionAnalyzer analyzer;
    auto results = analyzer.analyzeText(ciphertext);

    std::cout << "Analysis Results:\n";
    std::cout << "Confidence Score: " << results.confidence_score << "\n\n";
    
    std::cout << "Detected Mapping:\n";
    for (const auto& pair : results.mapping) {
        std::cout << pair.first << " -> " << pair.second << "\n";
    }

    std::cout << "\nDecrypted text:\n";
    std::cout << results.sample_decryption << "\n";

    std::cout << "\nPossible words found:\n";
    for (const auto& word : results.possible_words) {
        std::cout << word << " ";
    }
    std::cout << "\n";

    return 0;
}