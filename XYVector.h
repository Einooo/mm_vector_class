#include<iostream>
using namespace std;
template<typename T>

class XYVector {
    typedef T* iterator;
private:
    T* ptr;
    int sze;
public:

    XYVector (int); // Initialize by specific capacity
    XYVector (T*, int n ); // Initialize by n items from array
    XYVector (const XYVector&); // Initialize with a copy
    ~XYVector();
    XYVector &operator=(const XYVector&); // Copy assignment
    XYVector &operator=(const XYVector&&); // Move assignment

    // Modifying operations
    T& operator[](int); // Access item by reference
    int push_back(T); // Add item to end of vec & return # of items
    T pop_back(); // Remove and return last element in vec
    void erase(iterator); // Remove item at iterator
    void erase(iterator, iterator);// Remove items between
    void clear(); // Delete all vector content
    void insert(iterator, T); // Insert item at iterator
    iterator begin() ;// Return an iterator (T*)
    iterator end(); // Return an iterator (T*)

    // Comparison operations
    bool operator==(const XYVector<T>&) ;// Return true if ==
    bool operator< (const XYVector<T>&); // Compares item by item

    // Capacity operations
    int size() const ;  // Return current size of vec
    int capacity() const; // Return size of current allocated array
    int resize() ; // Relocate to bigger space
    bool empty() ; // Return true if size is 0

    // Friends
    friend ostream& operator << (ostream& out, XYVector<T>);
};
