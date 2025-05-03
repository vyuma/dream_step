#include "Ryuto_Kawabata_IntegerSet.h"

using namespace std;

// Comment 1: Defeault constructor - initializes an empty set with all elements set to false
IntegerSet::IntegerSet() : set(SET_SIZE, false) {
}

// Comment 2: Constructor that initializes set from an input array
IntegerSet::IntegerSet(const int arr[], int arrSize) : set(SET_SIZE, false) {
    for (int i = 0; i < arrSize; ++i) {
        if (arr[i] >= 0 && arr[i] < SET_SIZE) {
            set[arr[i]] = true;
        }
    }
}

// Comment 3: Input set elements from user interactively
void IntegerSet::inputSet() {
    int input;

    set = vector<bool>(SET_SIZE, false); // Reset the set

    cout << "Enter an element (-1 to end): ";
    cin >> input;

    while (input != -1) {
        if (input >= 0 && input <= 100) {
            set[input] = true;
        } else {
            cout << "Invalid input. Please enter a number between 0 and 100." << endl;
        }
        cout << "Enter an element (-1 to end): ";
        cin >> input;
    }
    cout << "Entry complete\n";
}

// Comment 4: Print the set, showing only elements that are present
void IntegerSet::printSet() const {
    bool isEmpty = true;
    cout << "{ ";

    for (int i = 0; i < SET_SIZE; ++i) {
        if (set[i]) {
            cout << i << " ";
            isEmpty = false;
        }
    }
    if (isEmpty) {
        cout << "---";
    }

    cout << "}\n";
}

// Comment 5: Perform set union operation
IntegerSet IntegerSet::unionOfSets(const IntegerSet& otherSet) const {
    IntegerSet result;

    for (int i = 0; i < SET_SIZE; ++i) {
        result.set[i] = set[i] || otherSet.set[i];
    }

    return result;
}

//  Comment 6: Perform set intersection operation
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& otherSet) const {
    IntegerSet result;

    for (int i = 0; i < SET_SIZE; ++i) {
        result.set[i] = this->set[i] && otherSet.set[i];
    }

    return result;
}

// Comment 7: Insert an element into the set
void IntegerSet::insertElement(int k) {
    if (k >= 0 && k < 100) {
        set[k] = true;
    } else {
        cout << "Invalid input. Please enter a number between 0 and 100." << endl;
    }
}

// Comment 8: Delete an element from the set
void IntegerSet::deleteElement(int m) {
    if (m >= 0 && m < 100) {
        set[m] = false;
    } else {
        cout << "Invalid input. Please enter a number between 0 and 100." << endl;
    }
}

// Comment 9: Check if two sets are equal
bool IntegerSet::isEqualTo(const IntegerSet& otherSet) const {
    for (int i = 0; i < SET_SIZE; ++i) {
        if (this->set[i] != otherSet.set[i]) {
            return false;
        }
    }
    return true;
}