// RationalNumber.h
// Class definition for RationalNumber that represents fractions
#ifndef RATIONAL_NUMBER_H
#define RATIONAL_NUMBER_H

class RationalNumber {
private:
    int numerator;
    int denominator;
    
    // Utility function to reduce fractions to lowest terms
    void reduce();
    
    // Utility function to find greatest common divisor
    int gcd(int a, int b) const;

public:
    // Constructor with default values
    RationalNumber(int num = 0, int denom = 1);
    
    // Overloaded arithmetic operators
    RationalNumber operator+(const RationalNumber &right) const;
    RationalNumber operator-(const RationalNumber &right) const;
    RationalNumber operator*(const RationalNumber &right) const;
    RationalNumber operator/(const RationalNumber &right) const;
    
    // Overloaded assignment operator
    const RationalNumber &operator=(const RationalNumber &right);
    
    // Overloaded relational operators
    bool operator>(const RationalNumber &right) const;
    bool operator<(const RationalNumber &right) const;
    bool operator>=(const RationalNumber &right) const;
    bool operator<=(const RationalNumber &right) const;
    
    // Overloaded equality operators
    bool operator==(const RationalNumber &right) const;
    bool operator!=(const RationalNumber &right) const;
    
    // Function to print the rational number
    void printRational() const;
};

#endif
