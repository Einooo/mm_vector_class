#include <bits/stdc++.h>
#include "mmVector.h"
#include "mmVector.cpp"
using  namespace  std;
void testClassWithString();
void testClassWithInt();
void testClassWithStlVector();
int main() {
//    testClassWithString();
//    testClassWithInt();
    testClassWithStlVector();

}

void testClassWithString() {
    mmVector<string> names = {"mina", "eino", "mostafa"};
    cout << "names mmVector: " << names << endl;
    cout << "Size: " << names.size() << endl;
    cout << "Capacity: " << names.capacity() << endl;
    //------------------------------------------------
    names.erase(names.begin());
    cout << endl;
    cout << "names mmVector: " << names << endl;
    cout << "Size: " << names.size() << endl;
    cout << "Capacity: " << names.capacity() << endl;

    //------------------------------------------------
    names.insert(names.begin(), "ahmed");
    cout << endl;

    cout << "names mmVector: " << names << endl;
    cout << "Size: " << names.size() << endl;
    cout << "Capacity: " << names.capacity() << endl;

    //------------------------------------------------
    names.erase(names.begin(), names.begin() +1);
    cout << endl;

    cout << "names mmVector: " << names << endl;
    cout << "Size: " << names.size() << endl;
    cout << "Capacity: " << names.capacity() << endl;
    //------------------------------------------------
    cout << "last element: " << names.pop_back();
    cout << endl;

    cout << "names mmVector: " << names << endl;
    cout << "Size: " << names.size() << endl;
    cout << "Capacity: " << names.capacity() << endl;
    //------------------------------------------------
}

void testClassWithInt() {
    int a[5] = {1,2,3,4,5};
    mmVector<int> numbers(a,5);

    cout << "numbers mmVector: " << numbers << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    //------------------------------------------------
    numbers.push_back(123);
    numbers.push_back(-47);
    cout << endl;

    cout << "numbers mmVector: " << numbers << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;

    //------------------------------------------------
    numbers.resize(3);
    cout << endl;

    cout << "numbers mmVector: " << numbers << endl;
    cout << "Size: " << numbers.size() << endl;
    cout << "Capacity: " << numbers.capacity() << endl;
    //------------------------------------------------

    mmVector<int> numbers2 = {1,2,3};
    cout << boolalpha << (numbers2 < numbers) << endl;
    //------------------------------------------------
}

void testClassWithStlVector() {
    mmVector<vector<int>> doubleVector = {{1,2,3}, {82,3}, {0,0,0,0}};
    cout << "doubleVector: " <<endl;
    for(int i = 0; i < doubleVector.size(); i++){
        for(int j = 0; j < doubleVector[i].size(); j++){
            cout << doubleVector[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Size: " << doubleVector.size() << endl;
    cout << "Capcity: " << doubleVector.capacity() << endl;

    //------------------------------------------------
    doubleVector.resize(1);
    cout << endl;

    cout << "doubleVector: " <<endl;
    for(int i = 0; i < doubleVector.size(); i++){
        for(int j = 0; j < doubleVector[i].size(); j++){
            cout << doubleVector[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Size: " << doubleVector.size() << endl;
    cout << "Capcity: " << doubleVector.capacity() << endl;

    //------------------------------------------------
    doubleVector.insert(doubleVector.end(), {1,1,1,1,1});
    cout << endl;

    cout << "doubleVector: " <<endl;
    for(int i = 0; i < doubleVector.size(); i++){
        for(int j = 0; j < doubleVector[i].size(); j++){
            cout << doubleVector[i][j] << ' ';
        }
        cout << endl;
    }

    cout << "Size: " << doubleVector.size() << endl;
    cout << "Capcity: " << doubleVector.capacity() << endl;

}
