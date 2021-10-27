#include "RunCaesarCipher.hpp"

std::string runCaesarCipher( const std::string& inputText,
const size_t key, const bool encrypt ) { 

    std::string outputText = "";
    // Loop over the input text
    for (auto c : inputText) {
        char e;
        // Apply the shift (+ve or –ve depending on encrypt/decrypt):
        if (encrypt) {
            e = c + key;

            // check if e is after Z, if so, subtract 26
            if (e > 'Z') {
                e = e - 26;
            }
        } else { // decrypt
            e = c - key;

            // check if e is before A, if so, add 26
            if (e < 'A') {
                e = e + 26;
            }

        }
        
        // add to output text
        outputText += e; 
    }

    // Finally (after the loop), return the output string
    return outputText;
 }