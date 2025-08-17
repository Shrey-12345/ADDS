#include "Reverser.h"
#include <string>

int Reverser::reverseDigit(int value) {
    if (value < 0) {
        return -1;
    }
    return reverseDigitHelper(value, 0);
}

int Reverser::reverseDigitHelper(int value, int result) {
    if (value == 0) {
        return result;
    }
    int lastDigit = value % 10;
    return reverseDigitHelper(value / 10, result * 10 + lastDigit);
}

std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) {
        return "ERROR";
    }
    return reverseStringHelper(characters, characters.length() - 1);
}

std::string Reverser::reverseStringHelper(const std::string& characters, int index) {
    if (index < 0) {
        return "";
    }
    return characters[index] + reverseStringHelper(characters, index - 1);
}