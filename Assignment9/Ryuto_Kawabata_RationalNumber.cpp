// RationalNumber.cpp
// Class implementation for RationalNumber
#include <iostream>
#include <cstdlib>
#include "Ryuto_Kawabata_RationalNumber.h"
using namespace std;

// Comment 1: Constructor that takes numerator and denominator parameters
// Prevents zero denominator, reduces fractions, and handles negative denominators
RationalNumber::RationalNumber(int num, int denom) {
    // Handle denominator of 0 case
    if (denom == 0) {
        cout << "Denominator cannot be zero. Setting to 1." << endl;
        denom = 1;
    }
    
    // Handle negative denominator case
    if (denom < 0) {
        num = -num;
        denom = -denom;
    }
    
    numerator = num;
    denominator = denom;
    
    // Reduce the fraction to lowest terms
    reduce();
}

// Comment 2: The reduce method simplifies fractions by dividing both
// numerator and denominator by their greatest common divisor (GCD)
void RationalNumber::reduce() {
    // Find the GCD and use it to reduce the fraction
    int divisor = gcd(abs(numerator), abs(denominator));
    
    numerator /= divisor;
    denominator /= divisor;
}

// Comment 3: Recursive Euclidean algorithm to find
// the greatest common divisor of two numbers
int RationalNumber::gcd(int a, int b) const {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Comment 4: Overloaded addition operator that creates a new RationalNumber
// by adding two fractions using the formula (a/b + c/d = (ad + bc)/bd)
RationalNumber RationalNumber::operator+(const RationalNumber &right) const {
    int num = numerator * right.denominator + right.numerator * denominator;
    int denom = denominator * right.denominator;
    
    return RationalNumber(num, denom);
}

// Comment 5: Overloaded subtraction operator that creates a new RationalNumber
// by subtracting two fractions using the formula (a/b - c/d = (ad - bc)/bd)
RationalNumber RationalNumber::operator-(const RationalNumber &right) const {
    int num = numerator * right.denominator - right.numerator * denominator;
    int denom = denominator * right.denominator;
    
    return RationalNumber(num, denom);
}

// Comment 6: Overloaded multiplication operator that creates a new RationalNumber
// by multiplying numerators and denominators (a/b * c/d = ac/bd)
RationalNumber RationalNumber::operator*(const RationalNumber &right) const {
    int num = numerator * right.numerator;
    int denom = denominator * right.denominator;
    
    return RationalNumber(num, denom);
}

// Comment 7: Overloaded division operator that creates a new RationalNumber
// by using the reciprocal method (a/b / c/d = a/b * d/c = ad/bc)
RationalNumber RationalNumber::operator/(const RationalNumber &right) const {
    // Check for division by zero
    if (right.numerator == 0) {
        cout << "Division by zero is undefined. Returning 0/1." << endl;
        return RationalNumber(0, 1);
    }
    
    int num = numerator * right.denominator;
    int denom = denominator * right.numerator;
    
    return RationalNumber(num, denom);
}

// Comment 8: Overloaded assignment operator that allows rational numbers
// to be assigned to each other, ensuring proper copying of member variables
const RationalNumber &RationalNumber::operator=(const RationalNumber &right) {
    if (this != &right) {
        numerator = right.numerator;
        denominator = right.denominator;
    }
    
    return *this;
}

// Comment 9: Overloaded comparison operators for rational numbers
// These convert fractions to a common denominator before comparing
bool RationalNumber::operator>(const RationalNumber &right) const {
    return (numerator * right.denominator > right.numerator * denominator);
}

bool RationalNumber::operator<(const RationalNumber &right) const {
    return (numerator * right.denominator < right.numerator * denominator);
}

bool RationalNumber::operator>=(const RationalNumber &right) const {
    return (numerator * right.denominator >= right.numerator * denominator);
}

bool RationalNumber::operator<=(const RationalNumber &right) const {
    return (numerator * right.denominator <= right.numerator * denominator);
}

// Comment 10: Overloaded equality operators that check if two rational numbers
// are equal by comparing their reduced forms
bool RationalNumber::operator==(const RationalNumber &right) const {
    return (numerator == right.numerator && denominator == right.denominator);
}

bool RationalNumber::operator!=(const RationalNumber &right) const {
    return !(*this == right);
}

// Prints the rational number in the format numerator/denominator
// If denominator is 1, only the numerator is printed
void RationalNumber::printRational() const {
    if (denominator == 1)
        cout << numerator;
    else
        cout << numerator << "/" << denominator;
}
