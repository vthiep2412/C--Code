#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to decrypt the text using substitution cipher
string decrypt(const string& ciphertext) {
    // Define the substitution map (cipher -> plain)
    unordered_map<char, char> substitution_map = {
        {'a', 'x'}, {'j', 'r'}, {'s', 'i'},
        {'b', 'd'}, {'k', 'f'}, {'t', 'y'},
        {'c', 's'}, {'l', 'o'}, {'u', 'j'},
        {'d', 'v'}, {'m', 'k'}, {'v', 'y'},
        {'e', 'u'}, {'n', 'e'}, {'w', 'w'},
        {'f', 'n'}, {'o', 't'}, {'x', 'c'},
        {'g', 'm'}, {'p', 'b'}, {'y', 'g'},
        {'h', 'p'}, {'q', 'a'}, {'z', 'h'},
        {'i', 'q'}, {'r', 'l'}
    };

    string decrypted;
    for (char c : ciphertext) {
        // If character is in our map, substitute it; otherwise keep it as is
        if (substitution_map.find(c) != substitution_map.end()) {
            decrypted += substitution_map[c];
        } else {
            decrypted += c;
        }
    }
    return decrypted;
}

int main() {
    // The encrypted text
    string ciphertext = "hzsrnqc klyy wqc flo mflwf ol zqdn nsoznj wskn lj xzsrbjnf, wzsxz gqv zqhhnf ol ozn glco zlfnco hnlhrn; nsoznj jnrqosdnc lj fnqj kjsnfbc, wzsxz sc xnjoqsfrv gljn efeceqr. zn rsdnb qrlfn sf zsc zlecn sf cqdsrrn jlw, wzsoznj flfn hnfnojqonb. q csfyrn blgncosx cekksxnb ol cnjdn zsg. zn pjnqmkqconb qfb bsfnb qo ozn xrep, qo zlejc gqozngqosxqrrv ksanb, sf ozn cqgn jllg, qo ozn cqgn oqprn, fndnj oqmsfy zsc gnqrc wsoz loznj gngpnjc, gexz rncc pjsfysfy q yenco wsoz zsg; qfb wnfo zlgn qo naqxorv gsbfsyzo, lfrv ol jnosjn qo lfxn ol pnb. zn fndnj ecnb ozn xlcv xzqgpnjc wzsxz ozn jnkljg hjldsbnc klj soc kqdlejnb gngpnjc. zn hqccnb onf zlejc leo lk ozn ownfov-klej sf cqdsrrn jlw, nsoznj sf crnnhsfy lj gqmsfy zsc olsrno.";
    
    // Decrypt and print the result
    string decrypted = decrypt(ciphertext);
    cout << "Decrypted text:\n" << decrypted << endl;
    
    return 0;
}