#ifndef CAESAR_CIPHER_HPP
#define CAESAR_CIPHER_HPP

#include <string>

std::string runCaesarCipher(const std::string& inputText,
const size_t key, const bool encrypt); // Create the alphabet container and output string
 
#endif