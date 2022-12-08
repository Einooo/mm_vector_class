#include "mmVector.h"

template<typename object>
mmVector<object>::mmVector(int n)
        :itsSize(n), itsCapacity(n), ptr(new object[n])
{}

template<typename object>
mmVector<object>::mmVector(object* arr, int n):mmVector(n){
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
    // if there is space to add the object at the end of our vector
    if(itsCapacity > itsSize) ptr[itsSize] = temp;
    else{
        // if not, allocate more memory and add the object at the end
        increaseCapacity(2 * itsSize);
        ptr[itsSize] = temp;
    }
    itsSize++;
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
    return (ptr + itsSize - 1);
}

template<typename object>
void mmVector<object>::increaseCapacity(int n){
    // if n is smaller, nothing happened
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
mmVector<object> &mmVector<object>::operator=( mmVector &&rhs) {
    if(this != &rhs){
        delete[] ptr;
        itsSize = rhs.itsSize;
        itsCapacity = rhs.itsCapacity;
        ptr = rhs.ptr;
        rhs.ptr = nullptr;
    }
    return *this;
}

template<typename object>
void mmVector<object>::erase(iterator it){
    if(itsSize == 0) return;
    // Checking Boundries
    if(!isValidIterator(it)) throw out_of_range("");

    iterator newVector = new object[itsCapacity];
    int newVectorCounter = 0;
    // Adding elements to the left of "it" to newVector
    for(auto i = begin(); i < it; i++){
        newVector[newVectorCounter] = *i;
        newVectorCounter++;
    }
    // Adding elements to the right of "it" to newVector
    for(auto i = it + 1; i <= end(); i++){
        newVector[newVectorCounter] = *i;
        newVectorCounter++;
    }
    delete[]ptr;
    ptr = newVector;
    itsSize--;
}

template<class object>
void mmVector<object>::erase(iterator it1, iterator it2) {
    if(it1 > it2) throw("start iterator is bigger than end iterator");

    if(!isValidIterator(it1) || !isValidIterator(it2))
        throw out_of_range("One iterator is out of range");

    iterator newVector = new object[itsCapacity];
    int newVectorCounter = 0;
    // Adding elements to the left of "it1" to newVector
    for(auto i = begin(); i < it1; i++){
        newVector[newVectorCounter] = *i;
        newVectorCounter++;
    }
    // Adding elements to the right of "it2" to newVector
    for(auto i = it2 + 1; i <= end(); i++){
        newVector[newVectorCounter] = *i;
        newVectorCounter++;
    }
    delete[]ptr;
    ptr = newVector;
    itsSize -= (it2 - it1 + 1);

}

template<class object>
void mmVector<object>::clear() {
    for(auto &i: *this){
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

template<class object>
ostream & operator<<(ostream &out, const mmVector<object>& rhs) {
    out <<"[";
    for(int i = 0; i < rhs.itsSize; i++){
        out << rhs.ptr[i];
        if(i != rhs.itsSize - 1) out << ", ";
    }
    out << "]\n";
    return out;
}

template<class object>
bool mmVector<object>::empty() {
    return(itsSize == 0);
}

template<class object>
bool mmVector<object>::isValidIterator(iterator it) {
    if(it < begin() || it > end()) return false;

    return true;
}

template<class object>
void mmVector<object>::insert(iterator it, const object& obj) {
    if(!isValidIterator(it)) throw out_of_range("");

    push_back(object());

    for(auto i = end(); i > it; i-- ) {
        *i = *(i - 1);
    }
    *it = obj;

}
