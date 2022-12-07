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

//template<typename object>
//void mmVector<object>::print() const {
//    for(int i = 0; i < 5; i++){
//        cout << ptr[i] << ' ';
//    }
//}

