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
mmVector<object> &mmVector<object>::operator=(const mmVector<object> &rhs) {
    if(this != &rhs){
        delete[] ptr;
        itsSize = rhs.itsSize;
        itsCapacity = rhs.itsCapacity;
        ptr = new object[itsCapacity];
        for(int i = 0; i < itsSize; i++){
            ptr[i] = rhs.ptr[i];
        }
    }
    return *this;
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

template<typename object>
typename mmVector<object>::iterator mmVector<object>::begin(){
    return ptr;
}

template<typename object>
typename mmVector<object>::iterator mmVector<object>::end(){
    return ptr + itsSize;
}

template<typename object>
void mmVector<object>::erase(iterator){

}

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

template<class object>
mmVector<object> &mmVector<object>::operator=(const mmVector &&rhs) {
    if(this != &rhs){
        delete[] ptr;
        itsSize = rhs.itsSize;
        itsCapacity = rhs.itsCapacity;
        ptr = new object[rhs.itsCapacity];
        for(int i = 0; i < itsSize; i++){
            ptr[i] = rhs.ptr[i];
        }
    }
    rhs.ptr = nullptr;
    return *this;
}

template<class object>
void mmVector<object>::erase(mmVector::iterator, mmVector::iterator) {
}

template<class object>
void mmVector<object>::clear() {
    for(auto &i : *this){
        i = object();
    }
    itsSize = 0;
}

template<class object>
bool mmVector<object>::operator==(const mmVector<object> &rhs) {
    if(itsSize != rhs.itsSize) return false;
    for(int i = 0; i < itsSize; i++){
        if(ptr[i] != rhs.ptr[i]) return false;
    }
    return true;
}

template<class object>
bool mmVector<object>::operator<(const mmVector<object> &rhs) {
    if(itsSize < rhs.itsSize) return true;
    if(itsSize > rhs.itsSize) return false;
    for(int i = 0; i < itsSize; i++){
        if(ptr[i] < rhs.ptr[i]) return true;
        if(ptr[i] > rhs.ptr[i]) return false;
    }
    return false;
}

//template<class object>
//ostream &operator<<(ostream &out, const mmVector<object>& rhs) {
//    out <<"[";
//    for(int i = 0; i < rhs.itsSize; i++){
//        out << i;
//        if(i != rhs.itsSize - 1) out << ", ";
//    }
//    out << "]\n";
//    return out;
//}


