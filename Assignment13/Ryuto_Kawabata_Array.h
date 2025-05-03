#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Comment 1: Template declaration for Array class which allows us to create arrays of any data type
template <typename T>
class Array
{
    // Comment 2: Friend function templates for input and output operations
    template <typename U>
    friend ostream &operator<<(ostream &, const Array<U> &);

    template <typename U>
    friend istream &operator>>(istream &, Array<U> &);

public:
    // Comment 3: Default constructor creates an array with a specified size
    explicit Array(int = 10);

    // Comment 4: Copy constructor creates a deep copy of another Array object
    Array(const Array<T> &);

    // Comment 5: Destructor releases dynamically allocated memory
    ~Array();

    size_t getSize() const;

    // Comment 6: Assignment operator creates a deep copy for safe assignment
    const Array<T> &operator=(const Array<T> &);

    bool operator==(const Array<T> &) const;

    // Comment 7: Inequality operator returns the opposite of == operator
    bool operator!=(const Array<T> &right) const
    {
        return !(*this == right);
    }

    // Comment 8: Subscript operator for non-const objects returns modifiable lvalue
    T &operator[](int);

    // Comment 9: Subscript operator for const objects returns rvalue
    T operator[](int) const;

private:
    // Comment 10: Private member variables to store the array size and pointer to the array
    size_t size;
    T *ptr;
};

template <typename T>
Array<T>::Array(int arraySize)
    : size(arraySize > 0 ? arraySize : throw invalid_argument("Array size must be greater than 0")),
      ptr(new T[size])
{
    cout << "INSIDE (int) CONSTRUCTOR...\n\n";

    for (size_t i = 0; i < size; i++)
        ptr[i] = T();
}

template <typename T>
Array<T>::Array(const Array<T> &arrayToCopy)
    : size(arrayToCopy.size),
      ptr(new T[size])
{
    cout << "INSIDE COPY CONSTRUCTOR...\n\n";

    for (size_t i = 0; i < size; i++)
        ptr[i] = arrayToCopy.ptr[i];
}

template <typename T>
Array<T>::~Array()
{
    cout << "INSIDE DESTRUCTOR...\n\n";
    delete[] ptr;
}

template <typename T>
size_t Array<T>::getSize() const
{
    return size;
}

template <typename T>
const Array<T> &Array<T>::operator=(const Array<T> &right)
{
    cout << "INSIDE ASSIGNMENT OPERATOR...\n\n";

    if (&right != this) // avoid self-assignment
    {
        cout << "NO SELF ASSIGNMENT\n\n";

        // for Arrays of different sizes, deallocate original
        // left-side Array, then allocate new left-side Array
        if (size != right.size)
        {
            delete[] ptr;      // release space
            size = right.size; // resize this object
            ptr = new T[size]; // create space for Array copy
        }

        for (size_t i = 0; i < size; ++i)
            ptr[i] = right.ptr[i]; // copy array into object
    }
    else
        cout << "SELF ASSIGNMENT WAS ATTEMPTED!\n\n";

    return *this;
}

// determine if two Arrays are equal
template <typename T>
bool Array<T>::operator==(const Array<T> &right) const
{
    if (size != right.size)
        return false; // arrays of different number of elements

    for (size_t i = 0; i < size; ++i)
        if (ptr[i] != right.ptr[i])
            return false;

    return true;
}

// overloaded subscript operator for non-const Arrays
template <typename T>
T &Array<T>::operator[](int subscript)
{
    cout << "INSIDE OF NON-CONST OPERATOR[]\n\n";

    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= static_cast<int>(size))
        throw out_of_range("Subscript out of range");

    return ptr[subscript];
}

// overloaded subscript operator for const Arrays
template <typename T>
T Array<T>::operator[](int subscript) const
{
    cout << "INSIDE OF CONST OPERATOR[]\n\n";

    // check for subscript out-of-range error
    if (subscript < 0 || subscript >= static_cast<int>(size))
        throw out_of_range("Subscript out of range");

    return ptr[subscript];
}

// overloaded input operator for class Array
template <typename U>
istream &operator>>(istream &input, Array<U> &a)
{
    for (size_t i = 0; i < a.size; ++i)
        input >> a.ptr[i];

    return input;
}

// overloaded output operator for class Array
template <typename U>
ostream &operator<<(ostream &output, const Array<U> &a)
{
    // output private ptr-based array
    for (size_t i = 0; i < a.size; ++i)
    {
        output << a.ptr[i] << " ";
    }

    return output;
}

#endif