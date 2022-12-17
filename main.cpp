#include <bits/stdc++.h>
#include "mmVector.h"
#include "mmVector.cpp"
using  namespace  std;

int main() {
    mmVector <int> a = {1,2,3};
    a.resize(4);
    cout << "Capacity: " << a.capacity() << "    Size: " << a.size() << endl;
    a.print();
    cout << endl;
    a.resize( 2);

    cout << "Capacity: " << a.capacity() << "    Size: " << a.size() << endl;
    a.print();
    cout << endl;
    a.resize(10);
    cout << "Capacity: " << a.capacity() << "    Size: " << a.size() << endl;
    a.print();
}

