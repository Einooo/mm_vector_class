#ifndef lol
#define lol


#include<iostream>
using namespace std;
template<class object>

class mmVector {

private:
    object* ptr;
    int itsSize;
    int itsCapacity;
    void increaseCapacity(int n);
public:
    typedef object* iterator;
    mmVector (int); // Initialize by specific capacity
    mmVector (object*, int ); // Initialize by n items from array
    mmVector (const mmVector&); // Initialize with a copy
    ~mmVector();
    mmVector &operator=(const mmVector&); // Copy assignment
    mmVector &operator=(const mmVector&&); // Move assignment
//
//    // Modifying operations
    object& operator[](int); // Access item by reference
    const object& operator[](int) const; // For const objects
    void push_back(object); // Add item to end of vec & return # of items
    object pop_back(); // Remove and return last element in vec
    void erase(iterator); // Remove item at iterator
    iterator begin() ;// Return an iterator (T*)
    iterator end(); // Return an iterator (T*)
    void erase(iterator, iterator);// Remove items between
    void clear(); // Delete all vector content
//    void insert(iterator, object); // Insert item at iterator

//
//    // Comparison operations
    bool operator==(const mmVector<object>&);// Return true if ==
    bool operator< (const mmVector<object>&);// Compares item by item
//
//    // Capacity operations
    int size() const ;  // Return current size of vec
    int capacity() const; // Return size of current allocated array
//    int resize() ; // Relocate to bigger space
//    bool empty() ; // Return true if size is 0
    void print() const;
//    // Friends
    friend ostream& operator << (ostream& out,const  mmVector<object>&rhs){
        out <<"[";
        for(int i = 0; i < rhs.itsSize; i++){
            out << rhs.ptr[i] << " ";
            if(i != rhs.itsSize - 1) out << ", ";
        }
        out << "]\n";
        return out;
    }
};

#endif