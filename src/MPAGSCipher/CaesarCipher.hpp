#ifndef MPAGS_CAESARCIPHER_HPP
#define MPAGS_CAESARCIPHER_HPP


#include <cstddef>
#include <string>
#include <vector>
#include "CipherMode.hpp"

class CaesarCipher{
    public:
      CaesarCipher(std::size_t key);
      CaesarCipher(const std::string& key);

      std::string applyCipher(const std::string& inputText, CipherMode mode);
    private:
      std::size_t key_{0};
      const std::vector<char> alphabet = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
};

#endif