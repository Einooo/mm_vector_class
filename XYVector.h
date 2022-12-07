#include<iostream>
using namespace std;
template<typename object>

class XYVector {
    typedef object* iterator;
private:
    object* ptr;
    int itsSize;
    int itsCapacity;
public:

    XYVector (int); // Initialize by specific capacity
    XYVector (object*, int n ); // Initialize by n items from array
    XYVector (const XYVector&); // Initialize with a copy
    ~XYVector();
    XYVector &operator=(const XYVector&); // Copy assignment
    XYVector &operator=(const XYVector&&); // Move assignment

    // Modifying operations
    object& operator[](int); // Access item by reference
    int push_back(object); // Add item to end of vec & return # of items
    object pop_back(); // Remove and return last element in vec
    void erase(iterator); // Remove item at iterator
    void erase(iterator, iterator);// Remove items between
    void clear(); // Delete all vector content
    void insert(iterator, object); // Insert item at iterator
    iterator begin() ;// Return an iterator (T*)
    iterator end(); // Return an iterator (T*)

    // Comparison operations
    bool operator==(const XYVector<object>&) ;// Return true if ==
    bool operator< (const XYVector<object>&); // Compares item by item

    // Capacity operations
    int size() const ;  // Return current size of vec
    int capacity() const; // Return size of current allocated array
    int resize() ; // Relocate to bigger space
    bool empty() ; // Return true if size is 0

    // Friends
    friend ostream& operator << (ostream& out, XYVector<object>);
};
