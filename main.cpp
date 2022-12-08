#include <bits/stdc++.h>
#include "mmVector.h"
#include "mmVector.cpp"
using  namespace  std;

int main() {
    int a1[5] = {1,5,5,88,77};
    int a2[5] = {1,5,5,5,4};
    mmVector<int> a(a1,5);
    mmVector<int> b(a2,5);
    a.print();
    cout << endl;
    cout << a.size() << ' ' << a.capacity();

    cout << endl;
    a.push_back(45555);
    a.print();
    cout << endl;
    cout << a.size() << ' ' << a.capacity();

}

// 1 1 0 siz = 3
// 1 1 0 0 0 cap = 5


