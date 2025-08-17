#include "Reverser.h"
#include <string>

// Public function: handles error checking
int Reverser::reverseDigit(int value) {
    if (value < 0) {
        return -1; // error indicator
    }
    return reverseDigitHelper(value, 0);
}

// Recursive helper: builds reversed number
int Reverser::reverseDigitHelper(int value, int result) {
    if (value == 0) {
        return result;
    }
    int lastDigit = value % 10;
    return reverseDigitHelper(value / 10, result * 10 + lastDigit);
}

// Public function: handles error checking
std::string Reverser::reverseString(const std::string& characters) {
    if (characters.empty()) {
        return "ERROR"; // error indicator
    }
    return reverseStringHelper(characters, characters.length() - 1);
}

// Recursive helper: reverses string
std::string Reverser::reverseStringHelper(const std::string& characters, int index) {
    if (index < 0) {
        return "";
    }
    return characters[index] + reverseStringHelper(characters, index - 1);
}