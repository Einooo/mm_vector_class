#include <bits/stdc++.h>
#include "mmVector.h"
#include "mmVector.cpp"
using  namespace  std;

int main() {
//    int a1[5] = {1};
//    int a2[5] = {1,5,78,6,4};
    mmVector<int> a(5);
    for(int i = 0; i < a.size(); i++){
        a[i] = i + 1;
    }
    a.print();
    cout << endl;
    cout << a.size() << ' ' << a.capacity();
    cout << endl;

    a.erase(a.begin(),a.end());

    a.print();
    cout << endl;
    cout << a.size() << ' ' << a.capacity();
    cout << endl;
//
//    a.insert(a.end() ,232 );
//    a.print();
//    cout << endl;
//    cout << a.size() << ' ' << a.capacity();
}

// 1 1 0 siz = 3
// 1 1 0 0 0 cap = 5


// 1 5 5 88 77
//