#include "Ryuto_Kawabata_Polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial() {
    size = 0;
    terms = nullptr;
}

Polynomial::Polynomial(const Polynomial& polynomial) {
    size = polynomial.size;

    if (size > 0) {
        terms = new Term[size];

        for (int i = 0; i < size; i++) {
            terms[i] = polynomial.terms[i];
        }
    } else {
        terms = nullptr;
    }
}

Polynomial::~Polynomial() {
    delete[] terms;
}

void Polynomial::enterTerms() {
    cout << "Enter number of polynomial terms: ";
    cin >> size;

    terms = new Term[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter coefficient: ";
        cin >> terms[i].coefficient;

        cout << "Enter exponent: ";
        cin >> terms[i].exponent;
    }
}

void Polynomial::printPolynomial() const {
    if (size == 0) {
        cout << "0";
        return;
    }

    bool firstTerm = true;
    for (int i = 0; i < size; i++) {
        if (terms[i].coefficient == 0) {
            continue;
        }

        if (!firstTerm) {
            if (terms[i].coefficient > 0) {
                cout << "+";
            }
        } else if (terms[i].coefficient < 0) {
            cout << "-";
            firstTerm = false;
        } else {
            firstTerm = false;
        }

        int coef = firstTerm ? terms[i].coefficient : abs(terms[i].coefficient);
        if (coef != 1 || terms[i].exponent == 0) {
            cout << coef;
        }

        if (terms[i].exponent > 0) {
            cout << "x";
            if (terms[i].exponent != 1) {
                cout << "^" << terms[i].exponent;
            }
        }

        firstTerm = false;
    }

    if (firstTerm) {
        cout << "0";
    }
}

Polynomial& Polynomial::operator=(const Polynomial& right) {
    if (this != &right) {
        delete[] terms;

        size = right.size;
        if (size > 0) {
            terms = new Term[size];
            for (int i = 0; i < size; i++) {
                terms[i] = right.terms[i];
            }
        } else {
            terms = nullptr;
        }
    }
    return *this;
}

Polynomial Polynomial::operator+(const Polynomial& right) const {
    Polynomial result;

    bool* leftUsed = new bool[size]();
    bool* rightUsed = new bool[right.size]();

    int maxResultSize = size + right.size;
    Term* resultTerms = new Term[maxResultSize];
    int resultSize = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < right.size; j++) {
            if (terms[i].exponent == right.terms[j].exponent) {
                resultTerms[resultSize].coefficient = terms[i].coefficient + right.terms[j].coefficient;
                resultTerms[resultSize].exponent = terms[i].exponent;
                resultSize++;

                leftUsed[i] = true;
                rightUsed[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        if (!leftUsed[i]) {
            resultTerms[resultSize] = terms[i];
            resultSize++;
        }
    }

    for (int j = 0; j < right.size; j++) {
        if (!rightUsed[j]) {
            resultTerms[resultSize] = right.terms[j];
            resultSize++;
        }
    }

    result.size = resultSize;
    result.terms = new Term[resultSize];

    for (int i = 0; i < resultSize; i++) {
        result.terms[i] = resultTerms[i];
    }

    // Simple bubble sort to arrange terms by descending exponent
    for (int i = 0; i < resultSize - 1; i++) {
        for (int j = 0; j < resultSize - i - 1; j++) {
            if (result.terms[i].exponent < result.terms[j + 1].exponent) {
                Term temp = result.terms[j];
                result.terms[j] = result.terms[j + 1];
                result.terms[j + 1] = temp;
            }
        }
    }

    delete[] leftUsed;
    delete[] rightUsed;
    delete[] resultTerms;

    return result;
}

Polynomial Polynomial::operator-(const Polynomial& right) const {
    Polynomial negatedRight(right);
    for (int i = 0; i < negatedRight.size; i++) {
        negatedRight.terms[i].coefficient *= -1;
    }
    return *this + negatedRight;
}

Polynomial& Polynomial::operator+=(const Polynomial& right) {
    *this = *this + right;
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& right) {
    *this = *this - right;
    return *this;
}