#ifndef CPPASSIGNMENT3_RATIONAL_H
#define CPPASSIGNMENT3_RATIONAL_H

#include <string>

using namespace std;

class Rational {
private:
    int numerator;
    int denominator;

    // Private helper function for normalization
    void normalize();

public:
    // Constructors
    Rational();
    Rational(int numerator);
    Rational(int numerator, int denominator);
    Rational(const string& str);

    // Overloaded operators
    Rational operator+(const Rational& other) const;
    Rational operator-(const Rational& other) const;
    Rational operator*(const Rational& other) const;
    Rational operator/(const Rational& other) const;

    bool operator>(const Rational& other) const;
    bool operator<(const Rational& other) const;
    bool operator==(const Rational& other) const;

    friend std::ostream& operator<<(ostream& os, const Rational& rational);
};

#endif //CPPASSIGNMENT3_RATIONAL_H