#include "mmVector.h"

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
mmVector<object>::mmVector(const mmVector& temp){
    itsSize = temp.itsSize;
    itsCapacity = temp.itsCapacity;
    ptr = new object[itsSize];

    for(int i = 0; i < itsSize; i++){
        ptr[i] = temp.ptr[i];
    }
}


template<typename object>
void mmVector<object>::push_back(object temp){
    if(itsCapacity > itsSize) ptr[itsSize - 1] = temp;
    else{
        increaseCapacity(2 * itsSize);
        ptr[itsSize] = temp;
        itsSize++;
    }
}

template<typename object>
object& mmVector<object>::operator[](int index){
    return ptr[index];
}

template<typename object>
const object& mmVector<object>::operator[](int index) const{
    return ptr[index];
}

template<typename object>
object mmVector<object>::pop_back(){
    object temp = ptr[itsSize - 1];
    ptr[itsSize - 1] = object();
    itsSize--;
    return temp;
}
//template<typename object>
//iterator mmVector<object>::begin(){
//    return
//}

//template<typename object>
//void mmVector<object>::erase(iterator){
//
//}

// 1 2 3 5
// 1 2 5

template<typename object>
void mmVector<object>::increaseCapacity(int n){
    if(n <= itsCapacity) return;

    itsCapacity = n;
    object* newVector = new object[itsCapacity];
    for(int i = 0; i < itsSize; i++){
        newVector[i] = ptr[i];
    }

    delete[] ptr;
    ptr = newVector;

}

template<typename object>
mmVector<object>::~mmVector(){
    delete[] ptr;

}

template<typename object>
int mmVector<object>::size()const{
    return itsSize;
}

template<class object>
int mmVector<object>::capacity() const {
    return itsCapacity;
}


template<typename object>
void mmVector<object>::print() const {
    for(int i = 0; i < itsSize; i++){
        cout << ptr[i] << ' ';
    }
}


