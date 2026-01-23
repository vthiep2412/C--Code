#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string cipher_text = "hzsrnqc klyy wqc flo mflwf ol zqdn nsoznj wskn lj xzsrbjnf, wzsxz gqv zqhhnf ol ozn glco zlfnco hnlhrn; nsoznj jnrqosdnc lj fnqj kjsnfbc, wzsxz sc xnjoqsfrv gljn efeceqr. zn rsdnb qrlfn sf zsc zlecn sf cqdsrrn jlw, wzsoznj flfn hnfnojqonb. q csfyrn blgncosx cekksxnb ol cnjdn zsg. zn pjnqmkqconb qfb bsfnb qo ozn xrep, qo zlejc gqozngqosxqrrv ksanb, sf ozn cqgn jllg, qo ozn cqgn oqprn, fndnj oqmsfy zsc gnqrc wsoz loznj gngpnjc, gexz rncc pjsfysfy q yenco wsoz zsg; qfb wnfo zlgn qo naqxorv gsbfsyzo, lfrv ol jnosjn qo lfxn ol pnb. zn fndnj ecnb ozn xlcv xzqgpnjc wzsxz ozn jnkljg hjldsbnc klj soc kqdlejnb gngpnjc. zn hqccnb onf zlejc leo lk ozn ownfov-klej sf cqdsrrn jlw, nsoznj sf crnnhsfy lj gqmsfy zsc olsrno.";
    std::string english_frequencies = "ETAOINSHRDLCUMWFGYPBVKJXQZ";

    // 1. Count letter frequencies
    std::map<char, int> letter_counts;
    for (char c : cipher_text) {
        if (std::isalpha(c)) {
            letter_counts[std::tolower(c)]++; // Case-insensitive
        }
    }

    // 2. Sort by frequency
    std::vector<std::pair<char, int>> sorted_letters(letter_counts.begin(), letter_counts.end());
    std::sort(sorted_letters.begin(), sorted_letters.end(), 
              [](const auto& a, const auto& b) { return a.second > b.second; });

    // 3. Create mapping
    std::map<char, char> mapping;
    for (size_t i = 0; i < sorted_letters.size() && i < english_frequencies.size(); ++i) {
        mapping[sorted_letters[i].first] = english_frequencies[i];
    }
    
    // 4. Decrypt
    std::string decrypted_text = "";
    for (char c : cipher_text) {
        if (std::isalpha(c)) {
            char lower_c = std::tolower(c);
            if (mapping.find(lower_c) != mapping.end()) {
                if (std::isupper(c)){
                    decrypted_text += std::toupper(mapping[lower_c]);
                } else {
                    decrypted_text += mapping[lower_c];
                }
            } else {
                decrypted_text += c;
            }
        } else {
            decrypted_text += c;
        }
    }
    // 5. Output mapping and decrypted text
    for (const auto& pair : mapping) {
        std::cout << pair.first << " = " << pair.second << std::endl;
    }
    std::cout << decrypted_text << std::endl;

    return 0;
}