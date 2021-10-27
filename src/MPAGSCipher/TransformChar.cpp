#include "TransformChar.hpp"

std::string transformChar(const char in_char) {
    /* transform letters to upper case and numbers to english words

    const char in_char: the char that should be transformed

    return: a string containing either the letter in upper case, or if the char
    was a number, the english word for the number in upper case. chars that are 
    neither letters nor numbers are ignored.
    */

    std::string inputText = "";

    // letters to upper case
    if (std::isalpha(in_char)) {
        inputText += std::toupper(in_char);
    }

    // Transliterate digits to English words
    switch (in_char) {
        case '0':
            inputText += "ZERO";
            break;
        case '1':
            inputText += "ONE";
            break;
        case '2':
            inputText += "TWO";
            break;
        case '3':
            inputText += "THREE";
            break;
        case '4':
            inputText += "FOUR";
            break;
        case '5':
            inputText += "FIVE";
            break;
        case '6':
            inputText += "SIX";
            break;
        case '7':
            inputText += "SEVEN";
            break;
        case '8':
            inputText += "EIGHT";
            break;
        case '9':
            inputText += "NINE";
            break;
    }
    
    return inputText;
}
