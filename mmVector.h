#include<iostream>
using namespace std;
template<typename object>
class mmVector {
    typedef object* iterator;
private:
    object* ptr;
    int itsSize;
    int itsCapacity;
public:

    mmVector (int); // Initialize by specific capacity
    mmVector (object*, int n ); // Initialize by n items from array
//    mmVector (const mmVector&); // Initialize with a copy
//    ~mmVector();
//    mmVector &operator=(const mmVector&); // Copy assignment
//    mmVector &operator=(const mmVector&&); // Move assignment
//
//    // Modifying operations
//    object& operator[](int); // Access item by reference
//    object operator[](int) const; // For const objects
//    int push_back(object); // Add item to end of vec & return # of items
//    object pop_back(); // Remove and return last element in vec
//    void erase(iterator); // Remove item at iterator
//    void erase(iterator, iterator);// Remove items between
//    void clear(); // Delete all vector content
//    void insert(iterator, object); // Insert item at iterator
//    iterator begin() ;// Return an iterator (T*)
//    iterator end(); // Return an iterator (T*)
//
//    // Comparison operations
//    bool operator==(const mmVector<object>&) ;// Return true if ==
//    bool operator< (const mmVector<object>&); // Compares item by item
//
//    // Capacity operations
//    int size() const ;  // Return current size of vec
//    int capacity() const; // Return size of current allocated array
//    int resize() ; // Relocate to bigger space
//    bool empty() ; // Return true if size is 0
    void print() const;
//    // Friends
//    friend ostream& operator << (ostream& out, mmVector<object>);
};