#ifndef REVERSER_H
#define REVERSER_H

#include <string>

class Reverser {
public:
    // Reverse an integer using recursion
    int reverseDigit(int value);

    // Reverse a string using recursion
    std::string reverseString(const std::string& characters);

private:
    // Helper for reverseDigit
    int reverseDigitHelper(int value, int result);

    // Helper for reverseString
    std::string reverseStringHelper(const std::string& characters, int index);
};

#endif