#include <iostream>
#include "CaesarCipher.hpp"
#include "CipherMode.hpp"


CaesarCipher::CaesarCipher(const std::size_t key) : key_{key}
{

}

CaesarCipher::CaesarCipher(const std::string& key) : key_{0}
{    
    if (!key.empty()) {
        
        for (const auto& elem : key) {
            if (!std::isdigit(elem)) {
                std::cerr
                    << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
                    << "        the supplied key (" << key
                    << ") could not be successfully converted" << std::endl;
                return;
            }
        }
    
    // Convert the string key to an unsigned long and assign it to key_
    key_ = std::stoul(key);

}
}

std::string CaesarCipher::applyCipher(const std::string& inputText, CipherMode mode)
{
    std::string outputText;
    const std::size_t alphabetSize{alphabet.size()};
    const std::size_t truncatedKey{key_ % alphabetSize};

    // Loop over the input text
    char processedChar{'x'};
    for (const auto& origChar : inputText) {
        for (size_t i{0}; i < alphabetSize; ++i) {
            if (origChar == alphabet[i]) {
               
                if (mode == CipherMode::encrypt) {
                    processedChar = alphabet[(i + truncatedKey) % alphabetSize];
                } else if (mode == CipherMode::decrypt) {
                    processedChar = alphabet[(i + alphabetSize - truncatedKey) % alphabetSize];
                }
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}
