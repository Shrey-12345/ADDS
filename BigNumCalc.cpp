#include "BigNumCalc.h"
#include <algorithm>

BigNumCalc::BigNumCalc() {}
BigNumCalc::~BigNumCalc() {}

std::list<int> BigNumCalc::buildBigNum(std::string numString) {
    std::list<int> result;
    for (char c : numString) {
        if (isdigit(c)) {
            result.push_back(c - '0');
        }
    }
    if (result.empty()) result.push_back(0);
    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int carry = 0;

    while (it1 != num1.rend() || it2 != num2.rend() || carry) {
        int sum = carry;
        if (it1 != num1.rend()) { sum += *it1; ++it1; }
        if (it2 != num2.rend()) { sum += *it2; ++it2; }
        result.push_front(sum % 10);
        carry = sum / 10;
    }
    return result;
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    auto it1 = num1.rbegin();
    auto it2 = num2.rbegin();
    int borrow = 0;

    while (it1 != num1.rend() || it2 != num2.rend()) {
        int diff = (it1 != num1.rend() ? *it1 : 0) - borrow;
        if (it2 != num2.rend()) { diff -= *it2; ++it2; }
        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_front(diff);
        if (it1 != num1.rend()) ++it1;
    }

    removeLeadingZeros(result);
    return result;
}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2) {
    std::list<int> result;
    if (num2.size() != 1) return result;
    int multiplier = num2.front();

    auto it1 = num1.rbegin();
    int carry = 0;
    while (it1 != num1.rend() || carry) {
        int prod = carry;
        if (it1 != num1.rend()) { prod += (*it1) * multiplier; ++it1; }
        result.push_front(prod % 10);
        carry = prod / 10;
    }

    removeLeadingZeros(result);
    return result;
}

void BigNumCalc::removeLeadingZeros(std::list<int>& num) {
    while (num.size() > 1 && num.front() == 0) {
        num.pop_front();
    }
}
