#include <bits/stdc++.h>
 #include "mmVector.h"
 #include "mmVector.cpp"
using  namespace  std;

int main() {
    int a1[5] = {1, 5,5,5,5};
    mmVector<int> a(a1,5);
    a.print();
//    cout <<  " a.size:" << a.size() <<endl;
//    cout <<  " a.capacity:" << a.capacity() <<endl;
//    a.pop_back();
//    a.print();
//    cout <<  " a.size:" << a.size() <<endl;
//    cout <<  " a.capacity:" << a.capacity() <<endl;
//    cout << endl;
    cout << a.begin();
}

// 1 1 0 siz = 3
// 1 1 0 0 0 cap = 5


