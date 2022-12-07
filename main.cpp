#include <bits/stdc++.h>
// #include "mmVector.h"
using  namespace  std;


template<class object>
class mmVector {
    typedef object* iterator;
private:
    object* ptr;
    int itsSize;
    int itsCapacity;
public:

    mmVector (int); // Initialize by specific capacity
    mmVector (object*, int ); // Initialize by n items from array
//    mmVector (const mmVector&); // Initialize with a copy
    ~mmVector();
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


template<typename object>
mmVector<object>::mmVector(int n)
        :itsSize(n), itsCapacity(n), ptr(new object[n])
{}

template<typename object>
mmVector<object>::mmVector(object* arr, int n):itsSize(n), itsCapacity(n), ptr(new object[n]){
    for(int i = 0; i < itsSize; i++){
        ptr[i] = arr[i];
    }

}

template<typename object>
mmVector<object>::~mmVector(){
    delete[] ptr;

}

template<typename object>
void mmVector<object>::print() const {
    for(int i = 0; i < 5; i++){
        cout << ptr[i] << ' ';
    }
}


int main() {
    int a1[5] = {1, 1};
    mmVector<int> a(a1,5);
    a.print();
//    vectpr<int > a;
}
