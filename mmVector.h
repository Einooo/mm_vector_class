#ifndef lol
#define lol
#include<iostream>
using namespace std;

template<class object>
class mmVector {
private:
    typedef object* iterator;
    iterator ptr;
    int itsSize;
    int itsCapacity;
    void increaseCapacity(int n);

public:

    mmVector (int);                         // Initialize by specific capacity
    mmVector (object*, int );               // Initialize by n items from array
    mmVector (const mmVector&);             // Initialize with a copy
    ~mmVector();
    mmVector &operator=(const mmVector&);   // Copy assignment
    mmVector &operator=(mmVector&&);        // Move assignment

    // Modifying operations
    object& operator[](int);                // Access item by reference
    const object& operator[](int) const;    // For const objects
    void push_back(object);                 // Add item to end of vec & return # of items
    object pop_back();                      // Remove and return last element in vec
//    void erase(iterator);                   // Remove item at iterator
    iterator begin() ;                      // Return an iterator (T*)
    iterator end();                         // Return an iterator (T*)
//    void erase(iterator, iterator);       // Remove items between
    void clear();                           // Delete all vector content
//    void insert(iterator, object);        // Insert item at iterator


    bool operator==(const mmVector<object>&);   // Return true if ==
    bool operator< (const mmVector<object>&)    ;// Compares item by item

    // Capacity operations
    int size() const ;          // Return current size of vec
    int capacity() const;       // Return size of current allocated array
//    int resize() ;            // Relocate to bigger space
    bool empty() ;              // Return true if size is 0
    void print() const;

    template<typename t>
    friend ostream& operator << (ostream& out,const  mmVector<t>&rhs);


};

#endif