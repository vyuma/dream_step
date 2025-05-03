#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
using namespace std;

// Comment 1: Define a Term struct to represent each term in a polynomial with a coefficient and exponent
struct Term {
    int coefficient;
    int exponent;
};

// Comment 2: the Polynomial class handles mathematical operations on polynomials using an array of terms
class Polynomial {
private:
    // Comment 3: Array to store the terms of the polynomial
    Term* terms;
    // Comment 4: Size to track how many terms the polynomial has
    int size;

public:
    // Comment 5: Default constructor initializes an empty polynomial with no terms
    Polynomial();

    // Comment 6: Copy constructor for creating a new polynomial from an existing one
    Polynomial(const Polynomial& polynomial);

    // Comment 7: Destructor free dynamically allocated memory
    ~Polynomial();

    // Comment 8: Fuction to allow user to input polynomial terms
    void enterTerms();

    // Comment 9: Function to display the polynomial in standard mathematical notation
    void printPolynomial() const;

    // Comment 10: Overloaded assignment operator for assigning one polynomial to another
    Polynomial& operator=(const Polynomial& right);

    // Comment 11: Overloaded addition operator to add two polynomials
    Polynomial operator+(const Polynomial& right) const;

    // Comment 12: Overloaded subtraction operator to subtract two polynomials
    Polynomial operator-(const Polynomial& right) const;

    // Comment 13: Overloaded addition assignment operator (+=)
    Polynomial& operator+=(const Polynomial& right);

    // Comment 14: Overloaded subtraction assignment operator (-=)
    Polynomial& operator-=(const Polynomial& right);
};

#endif // POLYNOMIAL_H