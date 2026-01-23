#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    // The ciphertext to analyze
    // string cipher_text = "hzsrnqc klyy wqc flo mflwf ol zqdn nsoznj wskn lj xzsrbjnf, wzsxz gqv zqhhnf ol ozn glco zlfnco hnlhrn; nsoznj jnrqosdnc lj fnqj kjsnfbc, wzsxz sc xnjoqsfrv gljn efeceqr. zn rsdnb qrlfn sf zsc zlecn sf cqdsrrn jlw, wzsoznj flfn hnfnojqonb. q csfyrn blgncosx cekksxnb ol cnjdn zsg. zn pjnqmkqconb qfb bsfnb qo ozn xrep, qo zlejc gqozngqosxqrrv ksanb, sf ozn cqgn jllg, qo ozn cqgn oqprn, fndnj oqmsfy zsc gnqrc wsoz loznj gngpnjc, gexz rncc pjsfysfy q yenco wsoz zsg; qfb wnfo zlgn qo naqxorv gsbfsyzo, lfrv ol jnosjn qo lfxn ol pnb. zn fndnj ecnb ozn xlcv xzqgpnjc wzsxz ozn jnkljg hjldsbnc klj soc kqdlejnb gngpnjc. zn hqccnb onf zlejc leo lk ozn ownfov-klej sf cqdsrrn jlw, nsoznj sf crnnhsfy lj gqmsfy zsc olsrno.";
    string cipher_text="HZSRNAS KLYY WAS FLO MFLWF OL ZADN NSOZNJ WSKN LJ XZSRBJNF, WZSXZ GAV ZAHHNF OL OZN GLSO ZLFNSO HNLHRN; NSOZNJ JNRAOSDNS LJ FNAJ KJSNFBS, WZSXZ SS XNJOASFRV GLJN EFESEAR. ZN RSDNB ARLFN SF ZSS ZLESN SF SADSRRN JLW, WZSOZNJ FLFN HNFNOJAONB. A SSFYRN BLGNSOSX SEKKSXNB OL SNJDN ZSG. ZN PJNAMKASONB AFB BSFNB AO OZN XREP, AO ZLEJS GAOZNGAOSXARRV KSANB, SF OZN SAGN JLLG, AO OZN SAGN OAPRN, FNDNJ OAMSFY ZSS GNARS WSOZ LOZNJ GNGPNJS, GEXZ RNSS PJSFYSFY A YENSO WSOZ ZSG; AFB WNFO ZLGN AO NAAXORV GSBFSYZO, LFRV OL JNOSJN AO LFXN OL PNB. ZN FNDNJ ESNB OZN XLSV XZAGPNJS WZSXZ OZN JNKLJG HJLDSBNS KLJ SOS KADLEJNB GNGPNJS. ZN HASSNB ONF ZLEJS LEO LK OZN OWNFOV-KLEJ SF SADSRRN JLW, NSOZNJ SF SRNNHSFY LJ GAMSFY ZSS OLSRNO.";
    // Count the frequency of each letter (ignoring case and non-alpha characters)
    unordered_map<char, int> freq;
    for (char c : cipher_text) {
        if (isalpha(c)) {
            char lower = tolower(c);
            freq[lower]++;
        }
    }
    
    // Transfer frequencies to a vector for sorting
    vector<pair<char, int>> freq_vec(freq.begin(), freq.end());
    // Sort in descending order based on frequency count
    sort(freq_vec.begin(), freq_vec.end(), [](const pair<char,int>& a, const pair<char,int>& b) {
        return a.second > b.second;
    });
    
    // Debug output: Print frequency counts
    cout << "Letter Frequencies in the Ciphertext:\n";
    for (const auto &p : freq_vec) {
        cout << p.first << " : " << p.second << "\n";
    }
    
    // English letter frequency order (most frequent to least frequent)
    string english_freq = "etaoinshrdlcumwfgypbvkjxqz";
    
    // Build the mapping from ciphertext letter (sorted by frequency) to the English frequency order
    unordered_map<char, char> mapping;
    for (size_t i = 0; i < freq_vec.size() && i < english_freq.size(); i++) {
        mapping[freq_vec[i].first] = english_freq[i];
    }
    
    // Debug output: Print the mapping
    cout << "\nMapping based on Frequency Analysis:\n";
    for (const auto &m : mapping) {
        cout << m.first << " -> " << m.second << "\n";
    }
    
    // Decrypt the text using the mapping
    string decrypted;
    for (char c : cipher_text) {
        if (isalpha(c)) {
            // Preserve original case
            char lower = tolower(c);
            char decryptedChar = mapping[lower];
            decrypted.push_back(isupper(c) ? toupper(decryptedChar) : decryptedChar);
        } else {
            decrypted.push_back(c);
        }
    }
    
    // Output the decrypted text
    cout << "\nDecrypted Text:\n" << decrypted << "\n";
    
    return 0;
}
