#include <iostream>
#include <string>
#include <vector>
#include <regex>

#include "Rational.h"

using namespace std;

// Source: https://stackoverflow.com/questions/9435385/split-a-string-using-c11
std::vector<string> split(const std::string& input, const std::string& regex) {
    std::regex re(regex);
    sregex_token_iterator first{input.begin(), input.end(), re, -1}, last;
    return {first, last};
}

// Constructors
Rational::Rational() : numerator(0), denominator(1) {
    cout << "\n-------------------------" << endl;
    cout << "Default constructor fired" << endl;
    cout << "-------------------------" << endl;
}

Rational::Rational(int numerator) : numerator(numerator), denominator(1) {
    cout << "\n------------------------------" << endl;
    cout << "One Argument constructor fired" << endl;
    cout << "------------------------------" << endl;
}

Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    cout << "\n------------------------------" << endl;
    cout << "Two Argument constructor fired" << endl;
    cout << "------------------------------" << endl;
}

Rational::Rational(const std::string& str) {
    std::cout << "\n------------------------" << std::endl;
    std::cout << "String constructor fired" << std::endl;
    std::cout << "------------------------" << std::endl;

    // Use the split function to extract numerator and denominator
    std::vector<std::string> parts = split(str, "/");
    if (parts.size() == 1) {
        // String has only numerator, set denominator to 1
        numerator = std::stoi(parts[0]);
        denominator = 1;
    } else if (parts.size() == 2) {
        // String has both numerator and denominator
        numerator = std::stoi(parts[0]);
        denominator = std::stoi(parts[1]);
        if (denominator == 0) {
            std::cerr << "Error: Denominator cannot be zero." << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        std::cerr << "Error: Invalid input format." << std::endl;
        exit(EXIT_FAILURE);
    }
}

// Private helper function for normalization
void Rational::normalize() {
    if (denominator < 0) {
        numerator *= -1;
        denominator *= -1;
    }

    // Special case for whole numbers
    if (denominator == 1) {
        return;  // Already a whole number, no further normalization needed
    }

    // Find the greatest common divisor
    int gcd = 1;
    for (int i = 1; i <= std::abs(numerator) && i <= std::abs(denominator); ++i) {
        if (numerator % i == 0 && denominator % i == 0) {
            gcd = i;
        }
    }

    // Normalize the numerator and denominator
    numerator /= gcd;
    denominator /= gcd;
}


// Overloaded operators
Rational Rational::operator+(const Rational& other) const {
    cout << "\n------------------------------" << endl;
    cout << "Addition operator fired" << endl;
    cout << "------------------------------" << endl;
    Rational result(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
    result.normalize();
    return result;
}

Rational Rational::operator-(const Rational& other) const {
    cout << "\n------------------------------" << endl;
    cout << "Subtraction operator fired" << endl;
    cout << "------------------------------" << endl;
    Rational result(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
    result.normalize();
    return result;
}

Rational Rational::operator*(const Rational& other) const {
    cout << "\n------------------------------" << endl;
    cout << "Multiplication operator fired" << endl;
    cout << "------------------------------" << endl;
    Rational result(numerator * other.numerator, denominator * other.denominator);
    result.normalize();
    return result;
}

Rational Rational::operator/(const Rational& other) const {
    cout << "\n------------------------------" << endl;
    cout << "Division operator fired" << endl;
    cout << "------------------------------" << endl;
    if (other.numerator == 0) {
        throw std::runtime_error("Error: Division by zero. The denominator cannot be zero.");
    }
    Rational result(numerator * other.denominator, denominator * other.numerator);
    result.normalize();
    return result;
}

bool Rational::operator>(const Rational& other) const {
    return numerator * other.denominator > other.numerator * denominator;
}

bool Rational::operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
}

bool Rational::operator==(const Rational& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

// Overloaded output operator
std::ostream& operator<<(std::ostream& os, const Rational& rational) {
    os << rational.numerator << '/' << rational.denominator;
    return os;
}