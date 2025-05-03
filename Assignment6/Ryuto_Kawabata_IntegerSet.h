#ifndef INTEGER_SET_H
#define INTEGER_SET_H

#include <vector>
#include <iostream>

using namespace std;

// Comment 10: IntegerSet class represents a set of integers from 0 to 100
// It uses a boolean vector to efficiently track set membership
// The class provides various set operations like union, intersection,
// element insertion/deletion, and set comparison
class IntegerSet {
private:
    vector<bool> set;
    static const int SET_SIZE = 101; // Assuming the set contains integers from 0 to 100

public:
    IntegerSet();

    IntegerSet(const int arr[], int arrSize);

    void inputSet();

    void printSet() const;

    IntegerSet unionOfSets(const IntegerSet& otherSet) const;
    IntegerSet intersectionOfSets(const IntegerSet& otherSet) const;

    void insertElement(int k);
    void deleteElement (int m);

    bool isEqualTo(const IntegerSet& otherSet) const;
};

#endif // INTEGER_SET_H